#include <iostream>
#include <vector>

using namespace std;

void sectotime(int cho) {
	int h, m, s;
	h = cho / 3600;
	m = (cho % 3600) / 60;
	s = cho % 60;
	cout << h << ' ' << m << ' ' << s << '\n';
}
int main() {
	int h, m, s, q, T, c;
	int cho;
	cin >> h >> m >> s >> q;
	vector<int> sec;
	cho = h * 3600 + m * 60 + s; //초 저장

	for (int i = 0; i < q; i++) {
		cin >> T;
		if (T == 1) { //초 증가
			cin >> c;
			cho += c;
			cho %= 86400;
		}
		if (T == 2) { //초 감소
			cin >> c;
			cho -= c;
			while (cho < 0) cho += 86400;
			cho %= 86400;
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