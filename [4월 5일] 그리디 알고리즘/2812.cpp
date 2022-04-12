#include <iostream> // 표준 입출력 헤더 파일
#include <string> // 스트링 헤더 파일
#include <deque> // 덱 헤더 파일

using namespace std;

//k개의 수 지워서 큰 수 만드는 함수
string findMaxNumber(string number, int l, int k) {
    // 숫자 각 자리를 보는 덱
    deque<char> dq;
    // k와 비교할 cnt 변수
    int cnt = 0;
    // l = 숫자 자릿수
    for (int i = 0; i < l; i++) {
        // 지금 탐색하는 숫자가 덱의 맨 뒤보다 크고, 덱이 비어있지 않고, cnt값이 k보다 작으면
        while (cnt < k && !dq.empty() && dq.back() < number[i]) {
            dq.pop_back();
            cnt++;
        }
        dq.push_back(number[i]); //이번 입력 삽입
    }
    
    // 답을 이어붙일 스트링 answer
    string answer = "";
    for (int i = 0; i < l - k; i++) { //l-k 자릿수
        // answer에 덱에 담았던 문자 하나하나를 이어붙인다
        answer += dq[i];
    }
    return answer;
}

/**
 * [크게 만들기]
 *
 * 어차피 남는 수는 n-k자리 수!
 * 가능한 앞자리에 큰 수를 배치하는 것이 유리하다.
 * 수의 앞자리부터 탐색하며, 덱에 차례대로 저장
 * 직전 자리보다 큰 수가 나오면 덱의 back이 자신보다 크거나 같아질 때까지 pop_back한 뒤에 추가
 *
 * ex) 1924 에서 2개를 지워서 큰 수를 만들어야 한다면
 *    deque: []           이번 숫자 '1' -> deque: ['1']
 *    deque: ['1']        이번 숫자 '9' -> deque: ['9']
 *    deque: ['9']        이번 숫자 '2' -> deque: ['9', '2']
 *    deque: ['9', '2']   이번 숫자 '4' -> deque: ['9', '4']
 *
 *    답: 94
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 *
 * 정확히 k개의 수를 지워야 함을 유의
 */

int main() {
    // 숫자 자릿수 & 몇 개 지워야하는지
    int n, k;
    
    // 숫자를 스트링형으로 입력받을 것임
    string number;

    //입력
    cin >> n >> k >> number;

    //연산 & 출력
    cout << findMaxNumber(number, number.length(), k);
    return 0;
}