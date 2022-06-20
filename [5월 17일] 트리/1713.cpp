#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더 파일
#include <map>  // 맵 헤더 파일
#include <algorithm>    // 알고리즘 헤더 파일 -> min_element

using namespace std;

// pair형 이름 지정
typedef pair<int, int> ci;


// 비교함수 (min_element용)
bool cmp(const pair<int, ci>& c1, const pair<int, ci>& c2) {
    // 후보자들의 추천횟수가 다르면 
    if (c1.second.first != c2.second.first) {
        // 추천 횟수가 작은 걸 삭제
        return c1.second.first < c2.second.first;
    }
    
    // 게시 시간이 더 오래된 걸 삭제
    return c1.second.second < c2.second.second;
}

/**
 * [후보 추천하기]
 *
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * -> min_element() 함수를 활용해서 조건을 만족하는 학생 찾기
 * -> min_element(x.begin(), x.end(), cmp): x 컨테이너 내에서 최솟값을 찾아주는 함수로 정렬과 비슷하게 cmp함수 써서 조건 설정 가능!
 *
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {
    // 사진틀, 추천횟수, 추천받은 학생 번호
    int n, m, input;

    //입력 & 연산
    cin >> n >> m;
   
    map<int, ci> candidate; //first: 후보 학생 번호, second: {추천 횟수, 게시 시간}
    
    // 추천횟수 m만큼 입력받기
    for (int i = 0; i < m; i++) {
        // 추천받은 학생 누군지
        cin >> input;

        //비어있는 사진틀이 없는 경우
        // 즉 후보자들이 n명 && 방금 입력받은 후보자가 첫 게시이면
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {
            
            // min_element 함수 : candidate의 처음부터 끝까지 돌면서 비교함수 cmp 조건에 맞는 후보자를 삭제
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));
        }
        //첫 게시라면
        if (candidate.find(input) == candidate.end()) {
            // 게시 시간 저장
            candidate[input].second = i;
        }
        candidate[input].first++; //추천 횟수 증가
    }

    //출력 (후보학생 번호)
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
        // 반복자 이용해서 출력
        cout << iter->first << ' ';
    }
    return 0;
}