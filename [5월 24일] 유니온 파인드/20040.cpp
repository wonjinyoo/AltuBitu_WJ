#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더

using namespace std;

// 루트 노드 저장할 벡터 (유니온 파인드)
vector<int> parent;

//Find 연산
int findParent(int node) {
    // 음수면 -> 해당 노드 자체가 루트 노드임
    if (parent[node] < 0) {
        return node;
    }
    // 그래프 압축하면서 find
    return parent[node] = findParent(parent[node]);
}

//Union 연산 (리턴형 : bool)
bool unionInput(int x, int y) {
    //x,y의 루트 노드 찾아서 xp, yp에 저장
    int xp = findParent(x);
    int yp = findParent(y);

    // 만약 루트 노드가 같으면 => 사이클 생성됨 의미
    if (xp == yp) {
        return false;
    }
    
    // weighted union find : 자식들이 더 많은 루트에 몰아주기
    if (parent[xp] < parent[yp]) {
        
        // 자식들이 더 많은 루트노드에 몰아줘서 자식 늘리기
        parent[xp] += parent[yp];
        // y의 루트노드는 xp가 됨
        parent[yp] = xp;
    }
    else {
        // 자식들이 yp에 더 많으면 yp에 몰아주기
        parent[yp] += parent[xp];
        // x의 루트노드는 yp가 됨
        parent[xp] = yp;
    }
    
    // default로 true 리턴
    return true;
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    // 점 개수, 차례 개수, 입력 받을 변수들
    int n, m, x, y;

    //입력
    cin >> n >> m;
    
    // parent 벡터 초기화
    parent.assign(n, -1);

    // 점들 입력 받기
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            // 해당 번째의 수를 출력하고 리턴
            cout << i + 1;
            return 0;
        }
    }
    // 사이클이 생성되지 않았으면 0 출력하고 리턴
    cout << 0;
    return 0;
}