#include <iostream> // 표준 입출력 헤더
#include <vector>  // 벡터 헤더
#include <algorithm>  // 알고리즘 헤더

using namespace std;
// 이차원배열 matrix로 선언
typedef vector<vector<int>> matrix;

// 전역변수로 선언
int n, ans = 0;

// 가장 큰 블록 얻는 함수
int getMaxBlock(matrix& board) {
    // 변수 0으로 초기화
    int max_block = 0;
    
    // 모든 칸에 대해 (즉 n*n회) 최댓값 갱신하면서 구해주기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_block = max(max_block, board[i][j]);
        }
    }
    // 최댓값 리턴
    return max_block;
}


// 전치행렬 구하기 (행과 열을 바꾸기)
matrix transposeMatrix(matrix& board) {
    // 전치행렬 담을 board_t 선언 (모두 0으로 초기화)
    matrix board_t(n, vector<int>(n, 0));
    
    // n*n회 입력받기 => 이때 행과 열을 반대로 입력받는다!
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 기존 board 행렬의 행과 열의 반대로 넣어주기
            board_t[i][j] = board[j][i];
        }
    }
    // 전치행렬 리턴
    return board_t;
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    
    for (int j = 0; j < n; j++) {
        // idx, prev 변수 0으로 초기화
        int idx = 0;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            // 해당 블록이 없으면 넘어가기
            if (!board[i][j]) {
                continue;
            }
            // 블록의 값이 이전의 값과 같다면 (한 열씩 봐줘야)
            if (board[i][j] == prev) {
                // temp 배열에 합쳐주기
                temp[idx - 1][j] *= 2;
                // prev는 0으로 초기화
                prev = 0;
            }
            else {
                // 블록 값이 다르면 temp에도 그대로 남겨주기
                temp[idx++][j] = board[i][j];
                // prev는 블록 값 그대로 유지
                prev = board[i][j];
            }
        }
    }
    
    // 새롭게 만들어진 보드 리턴
    return temp;
}

//백트래킹 탐색 -> 모두 upMove 함수로 동작, 그전에 보드 배열만 조정해주면 됨
void backtracking(int cnt, matrix board) {
    // 5번 움직였을 때
    if (cnt == 5) {
        ans = max(ans, getMaxBlock(board));
        return;
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board);
    // cnt => 하나 늘려주기, 한번 돌려줬으니까
    //상
    backtracking(cnt + 1, upMove(board));
    //하
    // 먼저 뒤집기
    reverse(board.begin(), board.end());
    backtracking(cnt + 1, upMove(board));
    //좌
    backtracking(cnt + 1, upMove(board_t));
    //우
    reverse(board_t.begin(), board_t.end());
    backtracking(cnt + 1, upMove(board_t));
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력 (n*n 판)
    cin >> n;
    
    // n*n 보드 이차원배열 만들기, 0으로 초기화
    matrix board(n, vector<int>(n, 0));
    
    // n*n회 만큼 보드의 상태 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 인덱스 [i][j] -> 이차원 배열
            cin >> board[i][j];
        }
    }

    //연산
    backtracking(0, board);

    //출력
    cout << ans;
    return 0;
}