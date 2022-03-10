#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pt; // 구조체 대신 pair 이용 (utility 헤더), first second로 접근

bool cmp(const pt& a, const pt& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	int n, a, b;
	cin >> n;
	vector<pt> p;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.push_back(pt(a, b));  // 이 과정이 헷갈렸음.. 벡터에 페어를 담는 게 익숙하지가 않음.. 
	}

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << p[i].first << ' ' << p[i].second << '\n';
	}
	return 0;
}

