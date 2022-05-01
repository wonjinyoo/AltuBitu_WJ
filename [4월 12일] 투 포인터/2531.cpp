#include <iostream> // 표준 입출력 헤더 파일
#include <vector> // 벡터 헤더 파일

using namespace std;

// 먹을 수 있는 초밥 최대 종류 개수 리턴하는 함수
int chooseSushi(int n, int d, int k, int c, vector<int>& belt) {
    // 0으로 초기화, 0과 1로 구분하는 듯?
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥 포함해서 개수 초기화
    int section_sushi = 1;
    
    // 쿠폰으로 먹은 초밥 표시해주기
    sushi[c]++;

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        // i번째 접시에 있던 초밥을 안 먹었으면
        if (!sushi[belt[i]]) {
            // 초밥 종류 개수 하나 더해주기
            section_sushi++;
        }
        // i번째 접시에 있던 초밥 개수 늘려주기 (총 개수 저장)
        sushi[belt[i]]++;
    }

    // ans에 일단 section_sushi값 넣어두고
    int ans = section_sushi;
   
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        // 맨 앞 (left라고 생각)의 값 1 빼주기
        sushi[belt[i - k]]--;
        
        // 만약 i-k번째 접시 위의 스시 나타내는 값이 0이면
        if (!sushi[belt[i - k]]) {
            // section_sushi값 하나 뺴줘야
            section_sushi--;
        }
        // 나머지 연산 => 원형이니까, 만약 다음 접시위의 스시 나타내는 값이 0이면 
        if (!sushi[belt[i % n]]) {
            // section_sushi값 하나 더해주기
            section_sushi++;
        }
        
        // 맨 뒤 (right라고 생각)는 1 더해주기
        sushi[belt[i % n]]++;
        // 둘 중에 더 큰 값으로 ans에 저장
        ans = max(ans, section_sushi);
    }

    // ans 리턴
    return ans;
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    // 각각 접시의 개수, 초밥 종류 개수, 연속 몇 개 먹을지, 쿠폰 번호
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    
    // 벨트 위에 있는 초밥 담을 벡터
    vector<int> belt(n, 0);
    
    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}
