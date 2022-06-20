#include <iostream> // 표준입출력 헤더
#include <vector>   // 벡터 헤더

using namespace std;

// subtree 개수 세기 -> 루트 번호에 대해, subtree 개수 저장
vector<int> subtree_cnt;

// 루트 번호, graph 벡터를 매개변수로
int treeDp(int cur, vector<vector<int>>& graph) {
    if (subtree_cnt[cur] != -1) { //이미 탐색했던 상태
        // 바로 현재 루트에 대해 subtree_cnt 리턴
        return subtree_cnt[cur];
    }

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;
    
    // 루트노드 1개는 항상 포함이므로 노드 개수 1로 지정
    int node = 1;

    // 현재 노드에서 연결된 자식노드들에 대해
    for (int i = 0; i < graph[cur].size(); i++) {
        // treeDp 연산 해서 node 결과에 갱신시켜주기
        node += treeDp(graph[cur][i], graph);
    }
    
    // 현재 subtree_cnt는 node로 저장되어 리턴
    return subtree_cnt[cur] = node;
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * [트리와 쿼리]
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 메모리제이션하며 계산
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열의 초기화를 -1로 해주고,
 *   dfs 탐색 시 현재 정점의 dp 값을 0으로 설정함으로써 자식 노드만 탐색할 수 있도록 함 (부모 노드에 0이 저장되어 있으므로 바로 리턴)
 *
 */

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 정점 개수, 루트번호, 쿼리 수, u-v 간선 정보(방향x), 
    int n, r, q, u, v, input;

    //입력
    cin >> n >> r >> q;
    
    // 이차원벡터 선언
    vector<vector<int>> graph(n + 1, vector<int>(0));
    
    // 모든 노드들에 대해 일단 subtree에 속한 정점 개수 -1로 초기화
    subtree_cnt.assign(n + 1, -1);


    // n-1회 반복
    while (--n) { //무방향 그래프
        // 간선 정보
        cin >> u >> v;
        
        // 무방향이므로 각각 u,v에 대해 push_back 해줘야
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //연산
    treeDp(r, graph);

    //출력 (쿼리 개수 q만큼 반복)
    while (q--) {
        // 입력 받고
        cin >> input;

        // input을 루트 노드로 하는 subtree_cnt 개수 출력
        cout << subtree_cnt[input] << '\n';
    }
    return 0;
}