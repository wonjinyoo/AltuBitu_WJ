#include <iostream>  // 표준 입출력 헤더파일
#include <algorithm>  // 알고리즘 헤더파일
#include <vector>  // 벡터 헤더파일
#include <cmath>  // 수학 함수 위해 cmath 헤더파일 (round 함수!)

using namespace std;  // std 이름공간 사용

const int SIZE = 4000; //양수의 최댓값

int findMode(vector<int>& frequency) {  // 최빈값 찾기 위한 함수
    int max_value = 0;  //최빈값의 빈도수
    for (int i = 0; i <= SIZE * 2; i++) { //최빈값의 빈도수 구하기
        if (frequency[i] > max_value)
            max_value = frequency[i];  // 최빈값의 빈도수보다 frequency의 값이 크면 최빈값 바꾸기
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= SIZE * 2; i++) {
        if (frequency[i] == max_value) { // frequency값이 최빈값의 빈도수와 같으면
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++;  // 최빈값 개수 하나 증가시킴
            if (cnt == 2) //두 번째로 작은 최빈값
                break;  // 두번째로 작은 최빈값 찾으면 for문에서 나옴
        }
    }

    return mode; // 최빈값 리턴
}

/**
 * [통계학]
 * 1. 산술 평균 계산 시 실수 자료형 사용, 반올림에 주의
 * 2. n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
 * 4. 최빈값이 유일한 경우 고려
 */

int main() {
    int n; //n은 홀수

    //입력
    cin >> n;  // 입력받은 수 n에 저장 (이때 n=수의 개수)

    vector<int> num(n);  // n만큼 할당한 num 벡터
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    int sum = 0; //평균 구하기 위한 합 변수
    for (int i = 0; i < n; i++) {  // n회 반복
        cin >> num[i]; // 수 입력 받아서 num벡터에 저장
        sum += num[i];  // 수의 합을 구함
        frequency[num[i] + SIZE]++;  // 빈도수도 저장
    }

    //연산
    sort(num.begin(), num.end());  // num 벡터 오름차순 정렬

    //출력
    //산술평균 : 
    if (round((double)sum / n) == -0)  // 반올림하는 round 함수 이용해서
        cout << "0\n";  // 반올림 결과가 -0이 나오면 0을 프린트하도록
    else
        cout << round((double)sum / n) << '\n';  // 그렇지 않은 경우 그냥 반올림값 그대로
    cout << num[n / 2] << '\n';               //중앙값: n이 홀수이므로 n/2번째 값임
    cout << findMode(frequency) << '\n';      //최빈값: 위의 findMode함수 이용
    cout << num[n - 1] - num[0] << '\n';      //범위: 맨마지막값 - 맨처음값

    return 0;  // 0 리턴
}