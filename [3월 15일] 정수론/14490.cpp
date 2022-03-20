#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) { // 최대공약수 구하기
	int x = max(a, b);
	int y = min(a, b);

	if (y == 0) return x;
	return gcd(y, x % y);
}

void cal(string s) { // 각 수를 최대공약수로 나눠서 약분, 출력까지
	// string을 구분해서, 정수로 변환
	int k = s.find(":");
	string s1 = s.substr(0, k);  // ':'의 앞에 있는 문자열
	string s2 = s.substr(k + 1, s.length() - s1.length() - 1); // 뒤에 있는 문자열

	int a = stoi(s1);
	int b = stoi(s2);  // 문자열을 정수로 바꿔주기
	int g = gcd(a, b);
	a /= g;
	b /= g;
	cout << a << ':' << b;
}

int main() {
	string s; // 입력받기
	cin >> s;
	cal(s);
	return 0;
}
