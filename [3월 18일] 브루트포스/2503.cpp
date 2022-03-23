#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	// 테스트케이스 개수
	cin >> n;
	
	// n개씩 할당된 배열들 = 각각 테스트 되는 정수, 해당 정수의 스트라이크 개수와 볼 개수를 저장함
	vector<string> test(n);
	vector<int> strk(n), ball(n);
	
	// 최종적으로 조건 만족하는 정수들을 넣는 벡터
	// 구하고자 하는 개수는 벡터의 크기와 같음
	vector<int> ans;

	// 입력
	for (int i = 0; i < n; i++) {
		cin >> test[i] >> strk[i] >> ball[i];
	}

	
	// 가능한 정수들에 대해 일일이 비교
	for (int i = 123; i <= 987; i++) {
		// 각 자리수를 비교할 거라 문자열 형태로 바꾸어줌
		string x = to_string(i);
		
		// 여기서 시간 오래 걸림.. 문제 조건 제발 잘 확인!!!
		// 0 사용 불가 & 각 자리수 다 다른 숫자임!!
		if (x[0] == '0' || x[1] == '0' || x[2] == '0' || x[0] == x[1] || x[1] == x[2] || x[0] == x[2]) continue;
		

		// 숫자 i에 대해 숫자 야구 진행해서 -> 모든 테스트 케이스와 각각의 결과 같은지 비교
		for (int j = 0; j < n; j++) {
			int test_strk = 0, test_ball = 0;

			// 각 자리수에 대해, 즉 총 3회 비교
			for (int k = 0; k < 3; k++) {
				// 스트라이크 확인
				if (x[k] == test[j][k]) test_strk++;
				
				// 볼 확인
				if (x[k] == test[j][(k + 1) % 3] || x[k] == test[j][(k + 2) % 3]) test_ball++;
			}
			
			// 모든 테스트 케이스에 대해 결과값 같을 때 해당하는 정수 i를 ans 벡터에 넣어줌
			if (test_strk == strk[j] && test_ball == ball[j]) {
				if (j == n - 1) ans.push_back(i);
				continue;
			}
			else break;
		}
	}

	// 모든 조건 만족하는 정수가 들어있는 벡터의 사이즈를 출력
	cout << ans.size();

	return 0;
}