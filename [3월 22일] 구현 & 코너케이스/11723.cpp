#include <iostream> // 입출력 헤더 파일
#include <vector> // 벡터 헤더 파일
#include <string> // 스트링 헤더 파일

using namespace std;
// SIZE = 자주 쓰이는 상수 선언
// index 1부터 쓰기 위해 20 + 1을 SIZE로 지정한다
const int SIZE = 21;

// 체크배열!!

/*
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    // 입출력 속도 빠르게 하기 위함
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 개수
    int m, num;
    //어떤 종류의 연산인지
    string cmd;
    
    // SIZE개만큼의 벡터 선언, default값은 false로 지정
    vector<bool> s(SIZE, false);

    // 입력
    cin >> m;
    
    // m회 반복
    while (m--) {
        // cmd 입력 받아서 이게 무슨 연산인지에 따라
        cin >> cmd;
        // all과 empty는 뒤의 num을 입력받지 않기 때문에 이렇게 먼저 씀
        // "all" 연산의 경우
        if (cmd == "all") {
            // s를 모두 true로 지정 이때 assign 사용함! 새로 알게된 내용
            s.assign(SIZE, true);
            continue;
        }
        // "empty" 연산의 경우
        if (cmd == "empty") {
            // s를 모두 false로 지정
            s.assign(SIZE, false);
            continue;
        }

        // num 입력 받아서
        cin >> num;
        // "add" 연산의 경우
        if (cmd == "add") {
            // num번째 멤버를 true로 지정
            s[num] = true;
            continue;
        }
        // "remove" 연산의 경우
        if (cmd == "remove") {
            // num번째 멤버를 false로 지정
            s[num] = false;
            continue;
        }
        // "check" 연산의 경우 
        if (cmd == "check") {
            // 새롭게 알게 된 내용.. 오오 bool형을 그대로 출력하면 정수값으로 나온다
            cout << s[num] << '\n'; // bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        // "toggle" 연산의 경우
        if (cmd == "toggle") {
            // bool값을 반대로 바꿔주면 된다!! 
            s[num] = !s[num];
            continue;
        }
    }
    return 0;
}