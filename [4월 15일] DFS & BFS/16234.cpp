#include <iostream> // 표준 입출력 헤더 파일
#include <vector> // 벡터 헤더파일
#include <queue> // 큐 헤더파일

using namespace std;
// pair 쓰기 좋게 ci로 선언
typedef pair<int, int> ci;


// 인접 행렬 board, visited
vector<vector<int>> board, visited;
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci>& union_cord) {
    // 연합들에 대해 서로 이동 시켜주는 반복문
    for (int i = 0; i < union_cord.size(); i++) {
       // 연합의 i번째 first값과 second 값으로 행과 열 지정
        int row = union_cord[i].first, col = union_cord[i].second;
        // population = sum / cnt, 즉 인구를 이 숫자로 바꿔준다
        board[row][col] = population;
        countries.push({ row, col }); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({ cr, cc });
    queue<ci> q;
    // cr = row, cc = col
    q.push({ cr, cc });
    
    // sum을 일단 벡터에 해당하는 값으로 초기화, cnt 1로 초기화
    int sum = board[cr][cc], cnt = 1;
    
    // q에 원소가 있는 동안 반복
    while (!q.empty()) {
        // 각각 q의 맨앞에 있는 값의 first, second 저장 (행, 열값) -> pop할거라
        cr = q.front().first;
        cc = q.front().second;
        // q의 front pop
        q.pop();

        // 상하좌우에 대해 반복
        for (int i = 0; i < 4; i++) {
            // 상 or 하 or 좌 or 우에 위치해 있는 값
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            // 그 값이 범위에 만족하지 않거나, visited값이 day이면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {
                // 앞으롤 돌아가 반복문 계속 진행
                continue;
            }
            
            // 차이값 구하기 (인접한 보드끼리)
            int diff = abs(board[nr][nc] - board[cr][cc]);
            
            // 문제 조건이 l이상 r이하면 국경선 열린다는 거
            if (diff >= l && diff <= r) { //국경선 열림
               //q에 nr, nc를 push
                q.push({ nr, nc });
                // visited값 day로 갱신
                visited[nr][nc] = day;
                union_cord.push_back({ nr, nc }); //연합에 추가
                
                // sum값도 board값 더해서 갱신
                sum += board[nr][nc];
                
                // 연합의 수 1 증가 시키기
                cnt++;
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        // true값 리턴하고 종료
        return true;
    }
    
    // 그렇지 않으면 false 리턴
    return false;
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    
    while (true) {
        // 일 수가 하나 증가
        day++;
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        // size회만큼 반복
        while (size--) {
            // 행과 열을 각각 countries front의 first와 second에서 받아와서 저장 (pop할거임)
            int row = countries.front().first;
            int col = countries.front().second;
            
            // countries 벡터 pop해주기
            countries.pop();
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                // 앞으로 돌아가서 반복 계속 진행
                continue;
            }
            // 탐색 안했으면
            // 각 행과 열의 visited 벡터를 day(일 수)로 
            visited[row][col] = day;
            
            // bfs 함수 실행 결과가 true면
            if (bfs(n, l, r, row, col, day)) {
                // 인구 이동했다고 표시
                is_move = true;
            }
        }
        // 만약 인구 이동 X면
        if (!is_move) {
            // day에서 1뺀값을 리턴하고 종료
            return day - 1;
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    // n*n 개의 나라, 인구 차이가 l명 이상 r명 이하면 인구 이동
    int n, l, r;

    //입력
    cin >> n >> l >> r;
    
    // board 배열 초기화
    board.assign(n, vector<int>(n, 0));
    
    // visited 배열 초기화
    visited.assign(n, vector<int>(n, 0));
    
    // n*n(행, 열)회 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 각 인구수를 입력받기
            cin >> board[i][j];
            // countries 벡터에 각 행과 열을 push 해주기
            countries.push({ i, j });
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0;
}