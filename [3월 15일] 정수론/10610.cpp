#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Thirty(string s) {
	int sum = 0, cnt = 0;// for 자리수 합 & 0이 있는지 확인용
	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		int x = s[i] - '0';  // 문자를 숫자로 바꾸기
		if (x == 0) cnt = 1;  //0이 하나라도 있다는 의미
		v.push_back(x);   // 각 자리수 벡터에 넣기
		sum += v[i]; 
	}

	if (cnt == 0) cout << "-1";
	else if (sum % 3 != 0) cout << "-1";
	// 자리에 0이 하나라도 있고, 자리수합이 3의 배수일 때
	else {
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < v.size(); i++) cout << v[i];
	}

}

// 만약에 cout<<'-1'; 과 같이 작은 따옴표안에 -1을 넣어 출력하고자 하면 웬 11569라는 숫자가 출력이 된다..

int main() {
	string s;
	cin >> s;
	Thirty(s);
	return 0;
}