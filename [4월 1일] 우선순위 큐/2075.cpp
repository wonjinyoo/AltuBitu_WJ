#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, num;
	cin >> n;
	// 최소힙 이용하기
	priority_queue<int, vector<int>, greater<int>> pq;

	// 입력받아서 n개만 우선순위 큐에 넣어주고 유지시키기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() == n + 1) pq.pop();
		}
	}
	
	// 마지막 상태에서 top 위치한 숫자가 n번째 큰 수임!
	cout << pq.top();

	return 0;
}