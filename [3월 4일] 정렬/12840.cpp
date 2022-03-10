#include <iostream>
#include <vector>

using namespace std;

const int HR_TO_SEC = 3600;
const int MIN_TO_SEC = 60;
const int DAY_TO_SEC = 86400;   //상수 선언

void sectotime(int cho) {
	int h, m, s;
	h = cho / HR_TO_SEC;
	m = (cho % HR_TO_SEC) / MIN_TO_SEC;
	s = cho % MIN_TO_SEC;
	cout << h << ' ' << m << ' ' << s << '\n';
}
int main() {
	int h, m, s, q, T, c;
	int cho;
	cin >> h >> m >> s >> q;
	vector<int> sec;
	cho = h * HR_TO_SEC + m * MIN_TO_SEC + s; //초 저장

	for (int i = 0; i < q; i++) {
		cin >> T;
		if (T == 1) { //초 증가
			cin >> c;
			cho += c;
			cho %= DAY_TO_SEC;
		}
		if (T == 2) { //초 감소
			cin >> c;
			cho -= c;
			while (cho < 0) cho += DAY_TO_SEC;
			cho %= DAY_TO_SEC;
		}
		if (T == 3) { //시간 출력
			sec.push_back(cho);
		}
	}
	for (int i = 0; i < sec.size(); i++) {
		sectotime(sec[i]);
	}
	return 0;
}
