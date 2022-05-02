#include <iostream> // 표준 입출력 헤더 파일
#include <queue> // 큐 헤더 파일 (for bfs)

using namespace std;

// 10^5 미리 정해놓기
const int SIZE = 1e5;

// bfs 너비 우선 탐색 => 가장 빠른 시간 탐색 해야하므로
int bfs(int n, int k) {
    // SIZE 크기만큼의 체크 배열 선언
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌표값 저장
    
    int ans = 0;

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    
    // 큐에 n(시작 노드)값 넣기
    q.push(n);

    // q에 값이 있는 동안 반복
    while (!q.empty()) {
        // q의 맨 앞의 값을 x라 선언, 저장해놓기 (pop할 거라서)
        int x = q.front();
        
        // 맨 앞의 값 pop
        q.pop();

        // 만약에 k에 도착했으면
        if (x == k) {
            // ans에 시간 계산해서 넣어주고 break
            ans = check[x] - 1;
            break;
        }

        // 자식 노드 => 현재에서 갈수 있는 위치 (-1하거나, +1하거나, *2하거나)
        vector<int> child = { x - 1, x + 1, x * 2 }; //자식 노드
        
        // 자식 노드 3개에 대해 수행
        for (int i = 0; i < 3; i++) {
            // 자식 노드가 0 이상이고, SIZE보다는 작거나 같고, (범위 내에 있는지 확인) 자식노드에 방문 한적 없으면 
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {
                // 방문 표시해주기 (시간 갱신해서)
                check[child[i]] = check[x] + 1;
                // 큐에 자식노드 넣어주기
                q.push(child[i]);
            }
        }
    }
    // ans 리턴
    return ans;
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    // 수빈(시작)의 위치, 동생(도착)의 위치
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}