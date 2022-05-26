//
// [1068] 트리
//  

#include <iostream>
#include <vector>

using namespace std;

// 이차원 벡터로 -> 인덱스가 부모노드, 노드 번호는 벡터로 저장
vector<vector<int>> tree;


// 리프노드 개수 구하는 함수 (현재 루트노드, 삭제할 노드 매개변수)
int dfsLeafNode(int curr, int del) {
	// 자신이 곧 삭제될 노드면 -> 0
	if (curr == del) {
		return 0;
	}


	// 자식이 없거나 or 자식이 하나로 유일한데 그게 곧 삭제될 노드라면
	if (tree[curr].empty() || tree[curr].size() == 1 && tree[curr][0] == del) {
		return 1;
	}

	int cnt = 0;

	// 자식노드들 따라 내려가면서 cnt값 갱신
	for (int i = 0; i < tree[curr].size(); i++) {
		cnt += dfsLeafNode(tree[curr][i], del);
	}

	return cnt;
}


int main() {
	int n, node, del, root;

	cin >> n;

	// bool형보다는 int형으로!
	tree.assign(n, vector<int>(0));

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
			tree[node].push_back(i);
		}
	}

	cin >> del;

	cout << dfsLeafNode(root, del);

	return 0;
}
