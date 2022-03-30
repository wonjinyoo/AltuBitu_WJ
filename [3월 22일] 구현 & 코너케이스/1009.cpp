#include <iostream>
#include <vector>
using namespace std;

int FindOut(const int& a, const int& b) {
	// 컴퓨터 번호 저장
	int x = 1;
	vector<int> rem;

	for (int i = 0; i < 4; i++) {
		x *= a;
		// x = 일의 자리수만 저장
		x %= 10; 
		rem.push_back(x);
		// 만약에 앞에 있었으면 (0번째 ~ 3번째만 체크해주면 됨 : 최대 4번 반복이라)
		}

	int index = (b % 4) - 1;
	if (index == -1) index = 3;
	x = rem[index];

	return x;
}


int main() {
	int t, a, b;
	// 데이터가 처리되는 컴퓨터 번호 저장
	vector<int> res;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (FindOut(a, b) == 0) res.push_back(10);
		else res.push_back(FindOut(a, b));
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
	return 0;
}

