#include <vector>   //벡터 헤더 파일
#include <iostream> // 표준입출력 헤더 파일

using namespace std;

// 정수 선언 (과녁이 10번까지 있음)
const int SIZE = 10;

vector<int> answer = { -1 }; //라이언이 가장 큰 점수 차이로 우승하는 경우
int max_diff = 0; //가장 큰 점수 차이

// answer 벡터와 현재 라이언 벡터 비교
bool cmp(vector<int>& ryan) {
    for (int i = SIZE; i >= 0; i--) {
        // answer벡터의 해당 과녁 맞힌 횟수가 라이언 벡터의 과녁보다 크면 
        if (answer[i] > ryan[i]) {
            // false 리턴
            return false;
        }
        // 반대의 경우
        else if (answer[i] < ryan[i]) {
            // true 리턴 -> answer 벡터가 ryan 벡터로 갱신이 됨
            return true;
        }
    }
}

int calcDiff(vector<int>& ryan, vector<int>& apeach) {
    // 라이언 점수, 어피치 점수
    int score_r = 0, score_a = 0;

    // 0번 ~ 10번 과녁이니까 반복
    for (int i = 0; i <= SIZE; i++) {
        // 10번 과녁부터 시작하므로 이렇게 SIZE에서 i를 빼서 점수 계산
        int score = SIZE - i;
        
        // 라이언이 어피치보다 과녁에 더 많이 맞혔으면 
        if (ryan[i] > apeach[i]) {
            // 라이언이 점수 획득
            score_r += score;
        }
        // 그렇지 않고 어피치가 라이언보다 과녁에 더 많이 맞혔으면
        else if (ryan[i] < apeach[i]) {
            // 어피치가 점수 획득
            score_a += score;
        } // 맞힌 횟수가 같으면 아무도 점수 안가져가므로 고려 x
    }
    
    // 라이언 점수와 어피치 점수의 차를 리턴
    return score_r - score_a;
}

void backtracking(int cnt, int extra_arrows, vector<int>& ryan, vector<int>& apeach) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(기저조건) 0점 과녁까지 탐색 or 남은 화살 없음
        ryan[SIZE] = extra_arrows; //화살 남아있을 수 있으므로
        
        // 현재의 차이를 calcDiff 연산 결과로 저장
        int curr_diff = calcDiff(ryan, apeach);
        
        // 가장 큰 점수 차이가 현재 점수 차이보다 작으면
        if (max_diff < curr_diff) {
            // max_diff를 현재 점수 차이로 갱신
            max_diff = curr_diff;
            
            // 결과값을 담는 벡터에 현재 라이언 벡터 저장
            answer = ryan;
        }
        // 그렇지 않고 현재 점수 차가 0이 아니면서 max_diff이고, cmp 결과가 true이면
        else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {
            // max_diff 갱신 없이 answer 벡터에 현재 라이언 벡터 저장
            answer = ryan;
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //남은 화살로 라이언이 점수를 얻을 수 있다면
        // 라이언의 과녁 개수가 어피치보다 딱 한 개 많게끔 해주기
        ryan[cnt] = apeach[cnt] + 1;
        // 백트래킹 연산
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach);
        // ryan의 cnt 과녁 개수 0으로
        ryan[cnt] = 0;
    }

    // 백트래킹 연산
    backtracking(cnt + 1, extra_arrows, ryan, apeach);
}

// n과 info가 매개변수로 주어지는 solution 함수
vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); //라이언의 과녁 정보
    backtracking(0, n, ryan, info); //연산
    
    // 결과 벡터 리턴
    return answer;
}

/**
 * [양궁대회]
 *
 * 1. 가능한 모든 경우를 백트래킹 탐색을 통해 검사
 * -> 라이언이 점수를 얻어가려면 어피치보다 1개 더 쏘는 경우가 최적. 어피치보다 적게 화살 쏘는 건 점수 못 얻어가므로 어차피 의미가 없음.
 * -> 따라서 라이언이 각 점수에 화살을 아래와 같이 쏘는 2가지 경우만 고려해서 만들어지는 모든 경우를 백트래킹으로 탐색
 *    - 어피치가 점수 획득을 하는 경우: 해당 점수에는 화살을 한 발도 쏘지 않는 것이 이득
 *    - 라이언이 점수 획득을 하는 경우: 필요한 최소 화살을 사용하는 것이 이득이므로 어피치보다 정확히 한 발 더 쏨
 *
 * 2. 가장 큰 점수 차이가 동일한 경우, 낮은 점수를 더 많이 맞힌 경우를 조건문으로 따로 해결
 * -> 단순 탐색하다가 갱신되는 값으로 하면 코너케이스 생김
 * -> 직접 0점 과녁부터 개수 비교해서 가장 낮은 점수를 더 많이 맞힌 경우 선택할 수 있도록 함
 *
 * !주의! 0번 인덱스가 10점 과녁임을 주의
 */

 //디버깅을 위한 메인 코드 - 프로그래머스에는 제출 X
int main() {
    // n발 쏘기
    int n = 5;

    // 어피치가 맞힌 점수 (순서대로 10점, 9점, .. , 0점)
    vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
    
    // n과 info가 매개변수로 주어짐
    vector<int> result = solution(n, info);
    
    // 라이언이 가장 큰 점수 차로 이기는 결과 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}