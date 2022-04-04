#include <iostream>
#include <vector>
using namespace std;

int ormak(int& n) {
	vector<vector<int>> dp(n+1, vector<int>(11));

	// 초기값 초기화 (n=1일 경우)
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	// n이 2일때부터
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		// 점화식 => 생각 깊이 좀 할 것 다양한 방식으로!
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			// 수가 커질 수 있으므로 여기서도 나머지 연산 해줘야 함
			dp[i][j] %= 10007;
		}
	}
	// 결과 담을 sum 변수
	int sum = 0;

	// 인덱스 n에 대해 0~9번째 다 더해주면 됨
	for (int i = 0; i <= 9; i++) {	
		sum += dp[n][i];
	}

	// 나머지 연산한 결과 리턴
	return sum % 10007;
}


int main() {
	int n;
	cin >> n;
	cout << ormak(n);
	return 0;
}