#include <iostream> // 표준 입출력 헤더파일
#include <vector>  // 벡터 헤더파일
#include <stack>  // 스택 헤더파일
#include <map>  // 맵 헤더파일

// 스택 : 모든 연산은 top에서만 이루어짐
// 맵 : key-value로 저장 (정렬O, 중복X)

using namespace std;

int calc(string s) {  // s=괄호들을 담는 스트링
    stack<char> st; //char형 스택 선언
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '(';
    bracket[']'] = '['; // 각각 쌍이 맞게 연결시켜준다
    num['('] = 2;  // ()인 괄호열 값 = 2
    num['['] = 3;  // []인 괄호열 값 = 3

    int ans = 0, temp = 1;  // temp에 곱하는 연산값 저장, 더해야 하는 경우 ans에 총 더하기
    for (int i = 0; i < s.length(); i++) { //입력받은 s의 길이만큼 하나씩 보기
        switch (s[i]) { // s의 i번째 문자의 값이
        case '(': case '[': //여는 괄호일 경우
            st.push(s[i]); // 스택에 해당 괄호 push
            temp *= num[s[i]]; // 괄호에 해당하는 값 temp에 곱해주기 
            break;
        case ')': case ']': //닫는 괄호일 경우
            if (st.empty() || st.top() != bracket[s[i]]) { //짝이 안 맞는 경우
                return 0; // 0 리턴
            }
            if (s[i - 1] == bracket[s[i]]) { // 짝이 맞으면
                ans += temp; // 결과값 더해주기
            }
            temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
            st.pop();  // 스택에서 pop해주기
            break;
        }
    }
    if (st.empty()) { //올바른 괄호라면
        return ans;  // 전체 결과값인 ans 리턴
    }
    return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    string s; // 입력받을 변수

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0; // 0 리턴
}