#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	// 선물들의 가치 넣을 우선순위 큐 ( 큰 순서대로 빼내야 -> 디폴트대로 그냥 쓰면 됨)
	priority_queue<int> pq;
	int n;
	cin >> n;

	int a, num;
	while (n--) {
		cin >> a;
		// a가 0이 아니면 -> 선물들의 가치를 우선순위 큐에 넣어준다
		if (a != 0) {
			for (int i = 0; i < a; i++) {
				cin >> num;
				pq.push(num);
			}
		}
		// a == 0 이면 선물 가치 출력인데, 없으면(큐가 비었으면) -1 출력
		else {
			if (pq.empty()) cout << "-1" << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}