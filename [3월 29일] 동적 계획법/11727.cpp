#include <iostream>
#include <vector>
using namespace std;

int Tile(int n) {
	vector<int> dp(n + 1);

	// 초기값 설정
	dp[1] = 1;
	dp[2] = 3;

	// 점화식!! 이번엔 잘 구했다
	for (int i = 3; i <= n; i++){
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		// 오버플로우 방지
		dp[i] %= 10007;
	}

	// 나머지 연산한 결과 리턴하기
	return dp[n] % 10007;
}


int main() {
	int n;
	cin >> n;
	cout << Tile(n);
	return 0;
}