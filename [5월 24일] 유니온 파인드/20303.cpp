#include <iostream> // 표준 입출력 헤더
#include <vector> // 벡터 헤더

using namespace std;

// pair 쓰기 좋게 선언
typedef pair<int, int> ci;


// ci형 벡터 선언
vector<ci> parent;

int knapsack(int n, int k) {
    vector<ci> cnt; //first: 아이들의 수, second: 사탕 개수

    for (int i = 1; i <= n; i++) {
        // first값이 음수면
        if (parent[i].first < 0) {
            // cnt에 아이들 수와, 사탕개수를 push
            cnt.push_back({ -parent[i].first, parent[i].second });
        }
    }

    // k = 우는 아이 수 경계값
    vector<int> dp(k, 0); //1부터 k-1까지
    
    // cnt 벡터에 대해 반복
    for (int i = 0; i < cnt.size(); i++) {
        for (int j = k - 1; j >= cnt[i].first; j--) {
            // dp : k명 미만에게 사탕을 뺏되, 최대 개수의 사탕을 뺏기 위해
            dp[j] = max(dp[j], dp[j - cnt[i].first] + cnt[i].second);
        }
    }
    return dp[k - 1];
}

//Find 연산
int findParent(int node) {
    // 만약 음수면 => 해당 노드가 루트노드라는 의미이므로 그냥 리턴
    if (parent[node].first < 0) {
        return node;
    }
    
    // 그래프 압축해주면서 연산
    return parent[node].first = findParent(parent[node].first);
}

//Union 연산
void unionInput(int x, int y) {
    // x,y의 루트노드를 각각 찾아서 변수 설정
    int xp = findParent(x);
    int yp = findParent(y);


    // 둘의 루트노드가 같으면 => 이미 친구관계, 리턴
    if (xp == yp) {
        return;
    }

    // x의 친구들수가 y의 친구들 수보다 많으면 (음수) 
    if (parent[xp].first < parent[yp].first) {
        
        // x의 친구들수에 y의 친구들 더해줌 (다들 친구 해주기)
        parent[xp].first += parent[yp].first;
        
        // y의 루트 노드 xp로 바꿔주기
        parent[yp].first = xp;
        
        // x의 사탕 개수도 갱신해주기
        parent[xp].second += parent[yp].second;
    }
    // y의 친구들 수가 x의 친구들 수보다 많으면 (음수)
    else {
        
        // y의 친구들 수에 x의 친구들 더해줌
        parent[yp].first += parent[xp].first;

        // x의 루트 노드 yp로 바꿔주기
        parent[xp].first = yp;

        // y의 사탕 개수 갱신
        parent[yp].second += parent[xp].second;
    }
}

/**
 * [할로윈의 양아치]
 *
 * - weighted union find -> 루트 정점에 아이들의 수(집합 원소 수)와 사탕 개수까지 pair 쌍으로 저장하기
 * - dp(냅색)으로 K명 미만의 아이들에게서 뺏을 수 있는 최대 사탕 수 구하기
 */

int main() {
    // 아이들 수, 친구관계 수, 우는 아이 수, 입력받을 변수
    int n, m, k, a, b;

    //입력
    cin >> n >> m >> k;
    
    // parent 벡터 초기화
    parent.assign(n + 1, { -1, 0 }); //first: 아이들의 수, second: 사탕 개수
    
    // 아이들의 사탕 개수 입력받아서 넣어주기
    for (int i = 1; i <= n; i++) {
        cin >> parent[i].second;
    }
    
    // 친구관계 입력 받기
    while (m--) {
        cin >> a >> b;
        // 연산
        unionInput(a, b);
    }

    //연산 & 출력
    cout << knapsack(n, k);
    return 0;
}