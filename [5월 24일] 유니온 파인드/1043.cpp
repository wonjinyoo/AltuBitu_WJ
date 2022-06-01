#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더

using namespace std;

// 루트 노드 담는 parent 벡터
vector<int> parent;

//Find 연산
int findParent(int node) {
    // parent값이 음수이면 그 노드가 루트 노드이므로
    if (parent[node] < 0) {
        // node값을 리턴
        return node;
    }
    // 그래프 압축해주면서 parent 저장
    return parent[node] = findParent(parent[node]);
}

//Union 연산
void unionInput(int x, int y) {
    // x,y의 루트노드를 각각 찾아서 xp, yp에 저장
    int xp = findParent(x);
    int yp = findParent(y);

    // 루트 노드가 같으면 => 같은 파티(서로 연결 O), 리턴
    if (xp == yp) {
        return;
    }

    // weighted union find : 자식이 더 많이 달려있는 쪽으로 몰아주기
    if (parent[xp] < parent[yp]) {
        // 자식 수 한 쪽으로 몰아주고
        parent[xp] += parent[yp];
        // yp의 루트노드를 xp로 저장
        parent[yp] = xp;
    }
    else {
        // 자식 수 한 쪽으로 몰아주고
        parent[yp] += parent[xp];
        // xp의 루트노드를 yp로
        parent[xp] = yp;
    }
}

// parties 벡터를 매개변수로 받음
int liarParty(vector<int>& parties) {
    // cnt = 0으로 초기화
    int cnt = 0;
    
    // 파티 개수만큼 반복
    for (int i = 0; i < parties.size(); i++) {
        // 해당 파티가 0과 같이 속해 있지 않으면 => 진실을 아는 사람 없음
        if (findParent(parties[i]) != findParent(0)) {
            // cnt 하나 늘려주기
            cnt++;
        }
    }
    // cnt 리턴
    return cnt;
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    
    // parent 벡터 초기화
    parent.assign(n + 1, -1);

    // init : 진실을 아는 사람 수, p : 그 번호 입력 받기
    int init, p;
    cin >> init;
    while (init--) { //진실을 아는 사람들
        // 진실을 아는 사람들 입력
        cin >> p;
        // 진실 아는 사람들 0을 루트노드로 해서 묶어주기
        unionInput(0, p);
    }

    int cnt, first_person, person;
    vector<int> parties;
    
    // 파티 개수만큼 반복
    while (m--) {
        // 해당 파티의 사람수, 첫번째 사람 번호
        cin >> cnt >> first_person;

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        
        // cnt-1회만큼 반복 => 해당 파티의 사람들 입력 넣기
        while (--cnt) {
            cin >> person;
            // 첫번째 사람과, 방금 입력 받은 사람 union 연산
            unionInput(first_person, person);
        }
    }

    //연산 & 출력
    cout << liarParty(parties);
    return 0;
}