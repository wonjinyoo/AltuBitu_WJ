
// [5639] 이진 검색 트리
//		-> 틀린 코드입니다 .. 
//		-> 내용 질문이 좀 많은데 주석 읽어주시면 감사하겠습니다 !! :)

#include <iostream>
#include <map>
using namespace std;

// 루트 노드, left, right값
map<int, pair<int, int>> tree;


// 이게.. 맞나요..?
void postorder(int v) {
	
	// '정수형 = NULL' 이렇게 쓸 수 있는 건가요..?
	if (v == NULL) {
		return;
	}
	postorder(tree[v].first);
	postorder(tree[v].second);
	cout << v << '\n';
}


int main() {
	int root, x;
	
	// 맨 처음 입력값을 제일 부모노드라고 생각해서 먼저 하나 입력 받고
	// 얘를 기준으로 크기를 비교하면서 트리를 채워나간다고 생각했습니다
	cin >> root;


	// 트리를 하나씩 채워나갈 때 비교해주기 위한 변수
	int comp = root;


	// 입력이 언제 종료될지 모를 때 어떻게 코드를 작성하면 좋을지 모르겠습니다..
	// 다른 분이 올려주신 질문 참고해서 cin.eof() 검색해서 사용해보았는데도 아무 출력이 안 나왔습니다..
	// 여기뿐만이 아니고 다른 데에서도 틀린 것 같은데 어디가 문젠지 잘 모르겠습니다..!

	while (cin >> x) {
		if (x == EOF) break;

		// 이런 식으로 트리를 생성해도 되나요..?
		if (x < comp) {
			tree[comp].first = x;
		}
		if (x > comp) {
			tree[comp].second = x;
		}
		comp = x;
	}


	// 함수 실행이 안 되고 있는 건지 어쩐건지 .. 뭐가 문젤까요..
	postorder(root);

	return 0;
}