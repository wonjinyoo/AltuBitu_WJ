// [1068] 트리
//		-> 틀린 코드인데요.. 대략적으로 이 아이디어 자체는 맞을까요..?
//		  힌트 주시면 수정하겠습니다!

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

// 트리를 맵으로 생성 : 각각 부모노드 번호, set에 자식 노드 담을 용도
map<int, set<int>> tree;


// 노드 삭제하기 (트리, 삭제할 노드 번호)
void deleteNode(map<int, set<int>> tree, int del) {
	vector<int> check;
	
	// 자식 노드가 없을 때 리턴
	if (tree[del].size() == 0) {
		return;
	}
	
	// 삭제할 노드의 자식노드들 번호를 check 벡터에 넣어준다
	for (auto it = tree[del].begin(); it != tree[del].end(); it++) {
		check.push_back(*it);
	}

	// 노드 삭제
	tree.erase(del);

	// 삭제한 노드의 자식 노드들도 좌르륵 삭제하기..
	for (int i = 0; i < check.size(); i++) {
		deleteNode(tree, check[i]);
	}
}


// 리프노드 개수 구하는 함수
int leafNode(map<int, set<int>> tree) {
	int cnt = 0;
	
	// 맵 순회하면서 자식노드가 0개이면 cnt를 1 늘려주는 방식으로
	for (auto it = tree.begin(); it != tree.end(); it++) {
		if (it->second.size() == 0) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n, node, del;

	cin >> n;

	// 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> node;
		
		// i번쨰 노드에 부모노드가 없으면 그대로 냅둔다..(?)
		if (node == -1) {
			continue;
		}
		// 부모 노드 없으면 트리 만들어주기..
		tree[node].insert(i);
	}

	cin >> del;
	deleteNode(tree, del);

	cout << leafNode(tree);
	
	return 0;
}