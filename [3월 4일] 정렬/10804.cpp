#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[21]; // 배열 index 0에는 null값 들어간다는 것 잊어먹지 말기
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(arr + a, arr + b + 1); //algorithm 헤더 내 reverse 함수
	}

	for (int j = 1; j <= 20; j++)
		cout << arr[j] << ' ';
	return 0;
}
