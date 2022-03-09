#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		cin >> input;
		b.push_back(input);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a.at(i) * b.at(i);
	}

	cout << sum;

	return 0;
}
