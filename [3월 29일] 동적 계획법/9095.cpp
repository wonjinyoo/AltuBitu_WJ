#include <iostream>
#include <vector>
using namespace std;

// n에 대해 결과값 구하는 함수
int onetwothree(int &n) {
	vector<int> dp(11, 0);

	// 각각 1,2,3에 대해 계산한 결과
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// 점화식
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[n];
}


int main() {
	int t; // 테스트케이스 개수
	int n; 

	// 입력
	cin >> t;
	while (t--) {
		cin >> n;
		cout << onetwothree(n) << '\n';
	}

	return 0;
}