#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
	int x, y;
};

bool cmp(const point& a, const point& b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {
	int n;
	cin >> n;
	vector<point> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	
	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << p[i].x << ' ' << p[i].y << '\n';
	}
	return 0;
}
