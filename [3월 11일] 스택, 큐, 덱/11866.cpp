#include <iostream>  // 표준 입출력 헤더파일
#include <queue>  // 큐 헤더파일
#include <vector>  // 벡터 헤더파일
  
using namespace std;  // std라는 이름공간 사용

// 큐 : 앞에서만 삭제, 삽입은 뒤에서만 

vector<int> simulation(int k, queue<int>& q) { 
    vector<int> result; //요세푸스 순열을 담는 벡터
    int cnt = 0; //카운트 변수

    while (!q.empty()) { // 큐에 원소가 있는 동안 반복
        int x = q.front();  // q의 제일 앞의 원소 x에 저장하고
        q.pop();  // 앞에 있는 원소는 삭제
        cnt++;  // 카운트 변수에 1 더해주기
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); // result 벡터에 x 넣어주기
            cnt = 0; // cnt 0으로 초기화
            continue; // 반복문 계속하기
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result;  // 요세푸스 순열 담은 result 벡터 리턴
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
    int n, k;  // n=총 사람 수, k=몇번째 사람이 제거되는지
    queue<int> q;  // 큐 선언

    //입력
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { //큐 초기화
        q.push(i);  // 큐의 뒤에 i 원소 삽입
    }
    //연산
    vector<int> result = simulation(k, q); //큐 q에 대해 k번째 사람 제거하는 함수
    //출력
    cout << '<'; // 맨 처음에 괄호 열기
    for (int i = 0; i < result.size() - 1; i++) { // result 벡터 하나씩 출력하기
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << '>'; // 맨 마지막 원소에 대해서는 괄호까지 닫아주기
    return 0;  // 0 리턴
}