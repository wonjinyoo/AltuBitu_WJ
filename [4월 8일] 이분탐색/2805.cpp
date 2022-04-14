#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 근데 ll을 그냥 너무 남발한 듯....
typedef long long ll;

ll maxtree2(ll n, ll m, vector<int> &tree) {
	ll left = 0;
	ll right = tree[n - 1];
	// 초기값 설정
	ll mid = (left + right) / 2;
	ll res = 0;

	// while문의 종료 조건을 맨날 헷갈린다...
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < n; i++) {
			if (tree[i] - mid < 0) continue;
			else sum += tree[i] - mid;
		}

		// 높이의 '최댓값' 구하는 과정 필요함
		if (sum >= m) {
			if (res < mid) res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return res;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 나무의 수 n, 상근이 목표 나무 길이 m
	ll n, m;

	cin >> n >> m;

	// 나무 높이 저장할 벡터 tree
	vector<int> tree(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	// 나무 벡터 정렬해야
	sort(tree.begin(), tree.end());

	cout << maxtree2(n, m, tree);

	return 0;
}