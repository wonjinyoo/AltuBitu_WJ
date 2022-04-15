#include <iostream> // 표준 입출력 헤더
#include <map> // 맵 헤더

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    // 칭호 개수, 캐릭터 수, 전투력
    int n, m, power;
    string name;

    //입력
    cin >> n >> m;
    // 칭호 & 전투력 저장
    while (n--) {
        cin >> name >> power;
        if (title[power].empty()) {
            title[power] = name;
        }
    }

    //출력
    while (m--) {
        // 전투력 입력 받으면
        cin >> power;
        // lower_bound 라이브러리 이용하여 칭호 출력 : power 이상의 수가 처음으로 나오는 위치
        cout << title.lower_bound(power)->second << '\n';
    }
}