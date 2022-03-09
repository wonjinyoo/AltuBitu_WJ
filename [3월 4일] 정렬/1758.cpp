#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int c;
	long long sum = 0;
	cin >> c;
	int* tip = new int[c];

	for (int i = 0; i < c; i++) { //등수= i+1
		cin >> tip[i];
	}

	sort(tip, tip + c, greater<>());

	for (int i = 0; i < c; i++) {
		int rtip = tip[i] - i;
		if (rtip < 0) rtip = 0;
		sum += rtip;
	}

	cout << sum;
	
	delete tip;
	return 0;
}