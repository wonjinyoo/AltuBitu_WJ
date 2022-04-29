/*
	1253. 좋다
	
	Q. 계속 틀리다가 벡터만 바꿔서 생성했더니 그제서야 맞다고 떴던 문제입니다..
	처음에 벡터 만들 때 index 1부터 n까지 쓰기 위해 n+1개로 할당하고 문제를 풀었었는데요, 아무리 다른 곳들 고쳐봐도 계속 틀렸다고 뜨길래
	벡터를 n개 할당해서 0부터 n-1까지 인덱스를 쓰게 하니 그제서야 맞다고 뜨더라고요.. 
	편리할 거 같아서 처음에 그렇게 벡터를 할당해서 썼는데... 여기서 무엇이 문제였을까요..?
	  => 벡터 생성 시 n+1 개로 생성하고 1번부터 n까지의 인덱스를 사용하는 데 제한(?) 같은 게 있을까요..?

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n개의 정수 담은 num벡터 이용 -> 좋은 수의 개수 찾기
int Good(int n, vector<int> &num) {
	
	// 결과 담을 변수
	int cnt = 0;

	// 각 수에 대해 투 포인터 진행
	for (int i = 0; i < n; i++) {
		
		// 초기 left값, right값 설정
		int left = 0;
		int right = n - 1;

		// 이때 left와 right가 같다는 조건까지 추가되면 안 됨 by 문제 조건
		while (left < right) {
			
			// 본인을 포함해서 더하는 경우 제외하기 위해서
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}

			// 좋은 수 판별 시작 & 결과에 따라 포인터 위치 조정 & 반복
			// 서로 다른 포인터 두 개가 가리키는 수들의 합으로 나타낼 수 있으면 => 좋은 수 => cnt 1 늘려주기
			if (num[left] + num[right] == num[i]) {
				cnt++;
				break;
			}
			// 합이 수보다 더 작게 나타나면 => 합을 늘려야 함 => left를 오른쪽으로 하나 이동 
			else if (num[left] + num[right] < num[i]) {
				left++;
			}
			// 합이 수보다 더 크게 나타나면 => 합을 줄여야 함 => right를 왼쪽으로 하나 이동
			else {
				right--;
			}
		
		}

	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 수의 개수
	int n;

	// 입력
	cin >> n;

	// 수 입력받을 num 벡터
	vector<int> num(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 오름차순 정렬
	sort(num.begin(), num.end());

	// 좋은 수의 개수 리턴하는 Good 함수
	cout << Good(n, num);

	return 0;
}