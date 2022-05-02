#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더

using namespace std;

// 인접 리스트 선언 (연결된 정점들을 탐색해야 하는 경우)
vector<vector<int>> adj_list;
// 부모 노드 담을 벡터
vector<int> parent;

// dfs 함수 (재귀함수)
void dfs_recursion(int prev, int curr) {
    // 현재 노드의 부모 노드가 0으로 나타나면 리턴 (재귀함수 : 종료 조건 중요)
    if (parent[curr]) {
        return;
    }
    
    // curr의 parent를 prev로 설정
    parent[curr] = prev;

    // 현재 노드와 연결된 노드들에 대해 반복 수행
    for (int i = 0; i < adj_list[curr].size(); i++) {
        // 재귀함수 : 현재 노드를 이전 노드로 설정, 연결된 노드를 curr로 설정
        dfs_recursion(curr, adj_list[curr][i]);
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    // 노드 개수
    int n, a, b;

    //입력
    cin >> n;
    // 인접리스트 초기화
    adj_list.assign(n + 1, vector<int>(0));
    
    // 부모 노드 초기화
    parent.assign(n + 1, 0);
    
    // n-1회 입력받기 (연결된 간선들)
    for (int i = 1; i < n; i++) {
        // 서로 연결된 두 노드의 값 입력받기
        cin >> a >> b;
        
        // a와 b가 연결됨을 나타냄 (양방향이어서 a,b 각각에 대해 해줘야 함)
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        // 2번의 부모 노드 ~ n번의 부모 노드 출력
        cout << parent[i] << '\n';
    }
    return 0;
}