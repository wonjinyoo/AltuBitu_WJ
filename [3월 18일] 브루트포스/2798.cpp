#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 질문. 이 문제에서 '메모리 사용량'을 줄일 수 있는 방법이 있을까요..? 무엇이 메모리 사용량을 크게 만드는 요소인지 궁금합니다!
 *      C++를 사용하여 문제를 푸신 다른 분들의 제출에 비해 제 코드가 메모리 사용량이 크더라구요..
 */


// diff가 작은 순서대로 정렬하는 비교함수
bool cmp(pair<int, int> v1, pair<int, int> v2) {
	return v1.first < v2.first;
}


void Blackjack(int n, int m) {
	// 카드값 입력 받기 위한 벡터
	vector<int> v(n);
	
	// 차이값, 합 저장하기 위한 벡터 -> 이후에 차이값을 작은 순서대로 정렬해서 -> 가장 작은 차이값을 가질 때의 합을 출력하도록 할 것임
	vector<pair<int, int>> res;
	
	for (int i = 0; i < n; i++) {
		// 카드 입력받아서 벡터에 저장
		cin >> v[i];
	}

	int sum = 0;
	// 3장이니까 그냥 차례차례 3개씩 묶어주는데 이때 시작 조건 주의했어야!!
	// j,k는 각각 i,j의 다음(즉, i+1, j+1)부터라는 게 중요
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				// 각 카드의 합을 더해줌
				sum = v[i] + v[j] + v[k];
				int diff = m - sum;
				// diff < 0 이라는 건 합이 m을 넘는다는 거니까 조건 충족 X
				if (diff < 0) continue;
				// 조건 충족시에만 차이값, 합을 벡터에 넣어준다
				else res.push_back({ diff, sum });
			}
		}
	}

	// 차이가 작은 순서대로 정렬 -> v[0]에는 차이값이 가장 작을 때의 경우!
	sort(res.begin(), res.end(), cmp);
	
	// 그때의 합을 출력해주면 됨
	cout << res[0].second;
}

int main() {
	int n, m;
	cin >> n >> m;
	Blackjack(n, m);
	return 0;
}