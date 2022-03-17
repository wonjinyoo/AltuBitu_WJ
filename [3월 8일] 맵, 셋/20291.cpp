#include <iostream>
#include <map>
using namespace std;

map<string, int> ext; // 확장자명 & 나온 횟수 

int main() {
	int n;
	cin >> n;
	while (n--) {
		string st, ex;
		string dot = ".";
		cin >> st;
		ex = st.substr(st.find(dot)+1);    //여기가 좀 새로운 거!
		ext[ex]++;     //그리고 map에서 int default값이 0..?
	}

	for (auto it = ext.begin(); it != ext.end(); it++) {   // map 순회
		cout << it->first << ' ' << it->second << '\n';
	}

	return 0;
}