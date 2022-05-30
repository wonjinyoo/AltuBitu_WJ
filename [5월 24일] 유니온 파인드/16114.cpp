// [16114] 화살표 연산자

#include <iostream>

using namespace std;

void arrowCal(int x, int n) {
	// 너무 조건문이.. 길고 가독성 떨어지긴 함..
	if (x == 0) {
		if (n == 1 || n % 2 == 0) {
			cout << '0';
		}
		else cout << "ERROR";
	}
	else if (x < 0) {
		if (n % 2 == 0) {
			cout << '0';
		}
		else if (n == 1) {
			cout << "INFINITE";
		}
		else cout << "ERROR";
	}
	else {
		if (n == 1) {
			cout << '0';
		}
		else if (n % 2 == 1) {
			cout << "ERROR";
		}
		else if (n == 0) {
			cout << "INFINITE";
		}
		else {
			int cnt = -1;
			int a = n / 2;
			while (x > 0) {
				cnt++;
				x -= a;
			}
			cout << cnt;
		}
	}
}

int main() {
	// 초기값, 화살표 길이
	int x, n;

	// 입력
	cin >> x >> n;
	
	// 연산
	arrowCal(x, n);
	
	return 0;
}