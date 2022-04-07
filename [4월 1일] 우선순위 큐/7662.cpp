#include <iostream>
#include <set>
using namespace std;

// 우선순위 큐 여러 개로 구상해보려 했는데 도저히 안 돼서 멀티셋 사용했습니다..

int main() {
	int t, k;
	
	char op;
	int num;
	
	cin >> t;

	while (t--) {
		// 디폴트 = 오름차순 정렬, 중복 저장 가능
		multiset<int> mset;

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> op >> num;

			// I 연산
			if (op == 'I') {
				// 멀티셋에 원소 삽입
				mset.insert(num);
		
			}

			// D 연산
			else if (op == 'D') {
				switch (num) {
				case 1:
					if (mset.empty()) continue;
					// 최댓값 삭제해주기
					mset.erase(--mset.end());
					break;

				case -1:
					if (mset.empty()) continue;
					// 최솟값 삭제해주기
					mset.erase(mset.begin());
					break;
				}
			}
		
		}


		if (mset.empty()) cout << "EMPTY" << '\n';
		// 반복자로 원소 접근 가능 
		else cout << *(--mset.end()) << ' ' << *(mset.begin()) << '\n';
	}
	return 0;
}