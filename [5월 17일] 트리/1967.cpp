#include <iostream> // 표준입출력 헤더
#include <vector>   // 벡터 헤더

using namespace std;

// pair형 선언
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) {
        // 다음 노드 -> 현재 노드의 자식노드로 지정
        int next_node = graph[node][i].first;
        // 만약 다음 노드가 매개변수로 주어진 parent이면 다음 반복
        if (next_node == parent) {
            continue;
        }

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.second > len) { //기존 거리보다 길다면 갱신
            // len 갱신 (지름 길이로), second는 가중치
            len = graph[node][i].second + dfs_search.second;
            // pos 갱신 (dfs 탐색 결과 나온 pos로)
            pos = dfs_search.first;
        }
    }
    // 노드 하나와 거리 리턴
    return { pos, len };
}

/**
 * [트리의 지름]
 *
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */

int main() {
    // 노드 개수, 부모노드, 자식노드, 가중치
    int n, p, c, w;

    //입력
    cin >> n;
    
    // 그래프 벡터로 선언 
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    
    // n-1회만큼 간선정보 입력받기
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        // 부모, 자식, 가중치
        cin >> p >> c >> w;
        
        // 무방향 그래프이므로 p와 c가 연결되어있고 가중치가 w임을 표시
        graph[p].push_back({ c, w });
        graph[c].push_back({ p, w });
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.first, -1, graph); //지름을 구성하는 다른 노드 찾기

    //출력 (다른 노드의, 거리값)
    cout << second_node.second;
    return 0;
}