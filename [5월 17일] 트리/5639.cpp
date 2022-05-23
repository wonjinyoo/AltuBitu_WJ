//
// [5639] 이진 검색 트리
//		-> 맵 말고 구조체, 포인터 이용해서 트리 생성 !!

#include <iostream>

using namespace std;

// 구조체 : 루트 노드, left, right값 -> 계속 노드로 연결
struct Node {
	int data;
	Node* left;
	Node* right;
};

// 트리 만드는 함수 : 리턴형 void로 하면 까다롭..
Node* makeTree(Node* tree, int x) {
	// 맨 처음거 메인 함수에서 초기화했다고 이 부분 안 넣어주면 안됐음 -> left, right 노드들은 안 채워졌을 거니까!
	if (tree == NULL) {
		tree = new Node();
		tree->data = x;
		tree->left = tree->right = NULL;
	}

	// 'else' if..
	else if (x <= tree->data) {
		tree->left = makeTree(tree->left, x);
	}
	else tree->right = makeTree(tree->right, x);

	return tree;
}

// 후위순회
void postorder(Node* tree) {
	if (tree->left != NULL) {
		postorder(tree->left);
	}
	if (tree->right != NULL) {
		postorder(tree->right);
	}

	cout << tree->data << '\n';
}


int main() {
	int root, x;

	cin >> root;

	// 맨 처음 초기화 -> 루트노드 설정
	Node* tree = new Node();
	tree->data = root;
	tree->left = tree->right = NULL;

	// ctrl + z 입력해야 !
	while (cin >> x) {
		if (x == EOF) break;
		
		// 계속 트리 갱신
		tree = makeTree(tree, x);
	}

	// 후위순회
	postorder(tree);

	return 0;
}
