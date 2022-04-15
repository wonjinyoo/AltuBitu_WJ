#include <iostream> // 표준 입출력
#include <vector> // 벡터

using namespace std;

vector<vector<int>> innings;
vector<int> order(10, 0); //타순 (몇번 타자가 누구인지)
vector<bool> check(10, false); // 몇 번 선수의 순서가 정해졌는지 저장하는 체크 배열
int n, ans;

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool>& baseman) {
    int score = 0;
    for (int i = 3; i >= 0; i--) {
        // i번째 루에 사람이 없으면
        if (!baseman[i]) {
            continue;
        }
        // 점수 올리는 경우 : 
        if (i + hit >= 4) {
            score++;
        }
        // i+hit번째 루에 선수 있다고 체크
        else {
            baseman[i + hit] = true;
        }
        // i번째 루에 사람 없다고 체크
        baseman[i] = false;
    }
    // 반복문 끝내고 hit가 4이면 점수를 올려줌
    if (hit == 4) {
        score++;
    }
    else {
        baseman[hit] = true; //새로운 선수들 홈에 도착
    }
    return score;
}

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
       // 이닝이 종료되기 전까지 즉 아웃이 3 미만일 경우까지
        while (out < 3) {
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            // 타순 번호가 10번이면 다시 1로 돌아감
            if (idx == 10) {
                idx = 1;
            }
            if (state == 0) {
                out++;
            }
            else {
                // 현재 상황에서 얻을 수 있는 점수를 더해줌
                score += hitScore(state, baseman);
            }
        }
    }
    return score;
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1);
        return;
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score);
        return;
    }
    for (int i = 2; i <= 9; i++) {
        // i번 선수가 아직 안 정해졌으면
        if (!check[i]) {
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자에 대해 array 함수
            check[i] = false;
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n;
    
    // 벡터 초기화
    innings.assign(n, vector<int>(10, 0));
    // 이닝 수 & 각 이닝의 결과 저장
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];
        }
    }

    //연산
    order[4] = 1; // 4번 타자는 1번 선수 (맨 처음에 지정)
    check[1] = true; //1번 선수는 순서 정해짐 -> 4번 타자로
    array(1);

    //출력
    cout << ans;
    return 0;
}