/*
	[13422] 도둑
		-> 투 포인터, 슬라이딩 윈도우 이용하였습니다!
*/

#include <iostream>
#include <vector>

using namespace std;

int thief(int n, int m, int k, vector<int> &money) {
	// 돈의 합을 저장할 변수 s와 ans
	long long s = 0, ans = 0;
	
	// 가능한 경우의 수 리턴하는 변수 cnt
	int cnt = 0;
	
	// 투 포인터
	int left = 0, right = m - 1;
	
	// 슬라이딩 윈도우 이용하여 합을 저장할 sum 벡터
	vector<long long> sum(n, 0);

	// n과 m이 같은 경우는 도둑질 가능한 경우가 0 or 1로 정해지므로 예외처리 해줘야 함
	if (n == m) {
		// 가능한 경우가 1가지밖에 없음 => 이게 경우를 만족하는지 안하는지만 봐주면 됨
		for (int i = 0; i < n; i++) {
			s += money[i];
		}

		if (s >= k) return 0;
		else return 1;
	}

	else {
		// 초기값 설정
		for (int i = 0; i < m; i++) {
			ans += money[i];
		}
		
		// 초기값
		sum[0] = ans;

		// sum 벡터에 값 저장해주기, 슬라이딩 윈도우
		for (int j = 1; j < n; j++) {
			right++;
			// vector의 인덱스 넘어서는 경우 방지
			if (right == n) right = 0;

			sum[j] = sum[j - 1] - money[left] + money[right];

			left++;
			// left가 갈 때까지 가면 어차피 끝난거
			if (left == n) break;
		}

		// 해당하는 sum이 가능한지 확인해주는 과정
		for (int i = 0; i < n; i++) {
			if (sum[i] >= k) continue;
			else cnt++;
		}

		return cnt;

	}
	
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t, n, m, k;

	// 입력
	cin >> t;

	// testcase수만큼 반복
	while (t--) {
		cin >> n >> m >> k;
		
		// 각 집의 돈을 저장, 입력받음
		vector<int> money(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> money[i];
		}
		cout << thief(n, m, k, money) << '\n';
	}
	return 0;
}