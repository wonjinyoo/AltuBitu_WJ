#include <iostream>  // 표준 입출력 헤더파일
#include <deque>  // 덱 헤더파일
#include <vector>  // 벡터 헤더파일
#include <algorithm>  // 알고리즘 헤더파일

using namespace std;  // std 이름공간

// 덱 : 자료 양끝에서 연산 가능 (앞, 뒤에서 모두 추가 및 삭제가 가능함)

deque<int> cardGame(int n, vector<int>& cmd) {
    deque<int> dq;  // 덱 선언

    for (int i = 1; i <= n; i++) { //놓여 있는 위의 카드부터 검사 1, ..., n
        switch (cmd[i]) {  // 기술 = cmd
        case 1: // 1일 경우
            dq.push_front(i);  // 제일 앞에 i라는 원소 추가  
            break;
        case 2: { //!주의! c++에서 switch-case 문에 변수 선언 시 {} 필수!
            int x = dq.front();  //덱의 제일 앞에 있는 원소
            dq.pop_front();  // 제일 앞에 있는 원소 삭제
            dq.push_front(i); // 제일 앞에 i라는 원소 추가
            dq.push_front(x);  // 제일 앞에 x 추가 (기존에 제일 앞에 있던 원소) 
            // -> 즉 앞에서 두번째에 i라는 원소를 추가하는 과정
            break;
        }
        case 3:
            dq.push_back(i);  // 제일 뒤에 i라는 원소 추가
            break;
        }
    }
}

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드를 다시 위에 ->
 *    제일 위의 카드 앞에 넣기
 * 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
 *    제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 밑에 넣기 ->
 *    제일 위의 카드 뒤에 넣기
 */

int main() {
    int n; // 입력받을 변수

    //입력
    cin >> n;
    vector<int> cmd(n + 1, 0);  // n+1개로 할당되고 0으로 초기화된 cmd 벡터 
    for (int i = 1; i <= n; i++) { //입력
        cin >> cmd[i];  // n번 입력받아 cmd 벡터에 저장
    }

    //연산
    reverse(cmd.begin() + 1, cmd.end()); //가장 위의 카드부터 검사하기 위해 기술 순서도 반대로 (reverse)
    deque<int> dq = cardGame(n, cmd); // 카드게임 수행하여 그 결과를 dq라는 덱에 저장
    // dq = 카드를 담고 있는 덱이다
    //출력
    while (!dq.empty()) { // 덱에 원소가 있는 동안 반복
        cout << dq.front() << ' '; // 제일 앞에 있는 원소 반환
        dq.pop_front(); // 제일 앞에 있는 원소 삭제
        // -> 앞에서부터 끝까지 cout하는 과정
    }
    return 0;  // 0 리턴
}