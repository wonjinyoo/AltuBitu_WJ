#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void tipcal(int n, vector<int> v) {
	long long s = 0;
	for (int i = 0; i < n; i++) {
		int rtip = v[i] - i;
		if (rtip < 0) rtip = 0;
		s += rtip;
	}
	cout << s;
}

int main() {
	int c, a;
	cin >> c;
	vector<int> tip(c);  // 벡터의 개수를 c로 지정해줘야지 에러가 안난다...?

	for (int i = 0; i < c; i++) { // 등수= i+1
		cin >> tip[i];
	}

	sort(tip.begin(), tip.end(), greater<>());
	tipcal(c, tip);

	return 0;
}
