#include <iostream> // 표준 입출력 헤더 파일
#include <queue> // 큐 헤더 파일
#include <vector>  // 벡터 헤더 파일

using namespace std;

// 구조체 info 선언
struct info {
    int d, h, order, line; //근무 일수, 급한 정도, 도착한 순서, 줄 번호
};

// 우선순위 큐 정렬 어떻게 할지
struct cmp { // 여기서 b를 기준으로 보라고
    bool operator()(const info& a, const info& b) {
        // 근무일수가 높은 순서대로
        if (a.d != b.d) {
            return a.d < b.d;
        }
        // 근무일수가 같으면 급한 순서대로
        if (a.h != b.h) {
            return a.h < b.h;
        }
        // 근무일수, 급한 순서도 같으면 줄번호 작은 순서대로
        return a.line > b.line;
    }
};


int simulation(vector<queue<info>>& people_line, int& k) {
    int ans = 0;
    priority_queue<info, vector<info>, cmp> pq; //선두를 저장할 우선순위 큐

    // 줄 개수만큼 반복 (맨 처음 선두들 저장)
    for (int i = 0; i < people_line.size(); i++) {
        if (!people_line[i].empty()) { //해당 줄(i)에 사람이 있으면
           // 그 줄의 선두를 우선순위 큐에 넣어주기
            pq.push(people_line[i].front());
            // 넣어줬으면 줄에서는 빼주기
            people_line[i].pop();
        }
    }

    while (pq.top().order != k) {
        // 데카 이전에 몇 명의 사람이 화장실을 썼는지 
        ans++;

        // 우선순위 큐에서 가장 우선순위가 높은 정보를 people에 담는다
        info people = pq.top();
        
        pq.pop();
        
        if (!people_line[people.line].empty()) { //해당 줄에 사람이 있으면
            // 줄의 가장 앞사람을 선두라고 생각하고 우선순위 큐에 넣어주기
            pq.push(people_line[people.line].front());
            // 넣었으면 줄에서는 빼주기
            people_line[people.line].pop();
        }
    }
    return ans;
}

/**
 * [화장실의 규칙] - 시뮬레이션 문제
 *
 * 1. 각 사람은 온 순서 % m 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람
 * 2. 더 급한 사람
 * 3. 줄 번호가 앞선 사람
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 order는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {
    // 대기하는 사람 수, 줄의 개수, 데카 앞 사원 수, 근무 일수, 급한 정도
    int n, m, k, d, h;

    //입력
    cin >> n >> m >> k;
    // 사원들의 정보를 담은 큐들을 줄 세워서 담는 벡터, 이런 식으로 벡터 쓰는 거 복잡하게 느끼지만 말고 쓸 수 있어야 돼!!!
    vector<queue<info>> people_line(m, queue<info>());
    for (int i = 0; i < n; i++) {
        // 근무 일수, 급한 정도 입력 받기
        cin >> d >> h;
        // 각 사람에게 맞는 줄에 사원 정보를 넣어준다
        people_line[i % m].push({ d, h, i, i % m });
    }

    //연산 & 출력
    cout << simulation(people_line, k);
    return 0;
}