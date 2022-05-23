//
// [1068] 트리
//   -> 말씀해주신대로 수정 최대한 해보았습니다..! 알려주신대로 하니까 코드 방향은 확실히 알겠어요!! 
//		그래도 구현하는 데 있어서 여전히 모르는 부분이 있어서요 ㅠㅠ 흑흑 

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 이차원 벡터로 -> 인덱스가 부모노드, 노드 번호는 벡터로 저장
vector<vector<bool>> tree;

// 방문체크용
vector<bool> visited;

// 리프노드 담는..
vector<int> leaf;

// 리프노드 개수 구하는 함수
// 이 부분을 잘 모르겠습니다.. dfs탐색 부분이 아직 약한 것 같습니다..ㅜ
void dfsLeafNode(int n, vector<vector<bool>> &tree, int curr, int del) {
	if (visited[curr]) {
		return;
	}

	visited[curr] = true;
	
	
	for (int next = 0; next < n; next++) {
		
		// 자식노드 아닌 것의 개수를 세려고 설정은 했습니다..
		int cnt = 0;
		
		if (visited[next]) continue;
		
		if (next == del) {
			tree[curr][next] = false;
		}
		

		if (tree[curr][next]) {
			dfsLeafNode(n, tree, next, del);
		}
		// next가 curr의 자식 노드가 아니면 cnt를 하나 늘려주기..?
		else cnt++;

		// 마지막까지 자식노드가 하나도 없으면 리프노드 벡터에 넣어주려는 용도입니다..
		if (next == n - 1 && cnt == n) leaf.push_back(curr);
	}

	// Q. 제거할 노드를 제외하고 탐색할 수 있는 조건문을 어떻게 추가하면 좋을지 잘 모르겠습니다..ㅜㅜ
}


int main() {
	int n, node, del;
	int root;
	
	cin >> n;

	// 0 ~ n-1까지 노드 있음, false로 방문 초기화
	visited.assign(n, false);

	tree.assign(n, vector<bool>(n, false));

	// 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> node;

		// 루트노드 root에 저장!
		if (node == -1) {
			root = i;
			continue;
		}
		// 부모 노드가 node이고, i를 자식으로 넣어주기
		else {
			tree[node][i] = true;
		}
	}

	cin >> del;

	dfsLeafNode(n, tree, root, del);

	cout << leaf.size();


	return 0;
}
