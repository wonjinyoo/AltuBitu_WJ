#include <iostream> // 표준 입출력 헤더 파일
#include <vector> // 벡터 헤더 파일
#include <queue> // 큐 헤더 파일

using namespace std;
// pair 쓰기 좋게 미리 선언 
typedef pair<int, int> ci;

// 적록색약 사람 기준으로 바꾸기
void greenToRed(int n, vector<vector<char>>& board) {
    // board의 행, 열에 대해 반복
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 만약 해당 칸의 문자가 'G'면 'R'로 바꾸어줌 -> G,R의 구분이 불가하므로 하나로 맞춰줌 
            if (board[i][j] == 'G') {
                board[i][j] = 'R';
            }
        }
    }
}

void bfs(int n, int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board) {
    //상, 하, 좌, 우
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    // ci형 큐 선언
    queue<ci> q;

    //큐 초기화
    q.push({ r, c });
    
    // 방문한 걸로 표시해주기
    visited[r][c] = true;
    
    // 큐에 값이 있는 동안 반복
    while (!q.empty()) {
        // q front의 first값과 second값 저장 (pop할거라서)
        int cr = q.front().first;
        int cc = q.front().second;
       
        // pop해주기
        q.pop();

        // 4회 반복 (상, 하, 좌, 우)
        for (int i = 0; i < 4; i++) {
            // cr의 각각 상, 하, 좌, 우에 있는 값 생각해주기
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            // nr값과 nc값이 범위에서 벗어나거나 이미 방문한 경우
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                // 다시 앞으로 돌아가 반복 진행
                continue;
            }
            // 만약 인접행렬의 값이 서로 다르면 continue
            if (board[nr][nc] != board[cr][cc]) {
                continue;
            }
            // 큐에 {nr,nc} 값 push 해주기
            q.push({ nr, nc });
            // 방문표시 해주기
            visited[nr][nc] = true;
        }
    }
}

// 구역 개수 세는 함수
int countArea(int n, vector<vector<char>>& board) {
    // 방문했는지 체크 하는 배열, 초기화 
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    // 맨 처음 구역의 개수는 0개임
    int area = 0;

    // n회 반복
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 만약에 해당하는 칸 방문했으면 앞으로 돌아가 반복
            if (visited[i][j]) {
                continue;
            }
            
            // 그렇지 않으면 bfs 수행
            bfs(n, i, j, visited, board);
            // 구역의 개수 하나 더해주기
            area++;
        }
    }
    // area값 리턴
    return area;
}

/**
 * [적록색약]
 *
 * 그림의 색을 기준으로 구역을 나누는 문제
 * 1. 적록색약이 아닌 사람 기준으로 구역을 나눈다.
 * 2. 그림의 초록을 모두 빨강으로 바꾼 후, 적록색약인 사람 기준으로 구역을 나눈다.
 */

int main() {
    // n*n 그리드
    int n;
    // 입력받는 한 줄
    string s;

    //입력
    cin >> n;
    
    // 인접행렬 초기화 (문자 담을)
    vector<vector<char>> board(n, vector<char>(n, ' '));
    // n번동안 한 줄씩 입력 받고
    for (int i = 0; i < n; i++) {
        cin >> s;
        
        // 각 문자들을 board 배열 (인접행렬)에 저장
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }

    //연산 & 출력
    cout << countArea(n, board) << ' ';
    // 적록색약 기준으로 바꾸고
    greenToRed(n, board);
    // 출력
    cout << countArea(n, board);
    return 0;
}