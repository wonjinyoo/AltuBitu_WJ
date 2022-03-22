#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) { // 최대공약수 구하기
	int x = max(a, b);
	int y = min(a, b);

	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int g, l;
	cin >> g >> l;
	int k = l / g;  // 출력되는 수의 비의 곱

	int s = floor(sqrt(k));
	int a, b;
	for (int i = s; i > 0; i--) {
		if (k % i == 0) {
			a = min(i, k / i);
			b = max(i, k / i);
			if (gcd(g * a, g * b) != g) continue;
			else break;
		}
		else continue;
	}

	int A = g * a;
	int B = g * b;
	cout << A << " " << B;
	return 0;
}
