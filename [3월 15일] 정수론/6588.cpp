#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool findPrime(int n) { // 소수 찾기, 에라토스테네스의 체 활용하고 싶었는데.. 못했습니다ㅠㅠ
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false; //소수가 아님
	}
	return true;
}

void Goldbach(vector<int> v) { // int형 벡터에 대하여 골드바흐 적용
	for (int i = 0; i < v.size(); i++) { //testcase 개수만큼 반복하도록
		for (int j = 2; j < v[i]; j++) { // 각 경우에 대해 확인
			int x = j;
			int y = v[i] - j;
			// 만약 x와 y 모두 소수이면 그때 더하기로 출력하기, continue
			if (findPrime(x) && findPrime(y)) {
				cout << v[i] << " = " << x << " + " << y << '\n';
				break;
			}
			else if (j == v[i] - 1) {
				cout << "Goldbach's conjecture is wrong." << '\n';
			}
			continue;
		}
	}
}

int main() {
	vector<int> v;
	// 테스트케이스 개수 = v의 size
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		v.push_back(n); 
	}
	Goldbach(v);
	return 0;
}