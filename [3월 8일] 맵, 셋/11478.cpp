#include <iostream>
#include <set>

using namespace std;

int main() {
	string str, wrd;
	cin >> str;
	set<string> str_set;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			wrd = str.substr(i, j); // 문자열 쪼개는 substr
			str_set.insert(wrd);
		}
	}

	cout << str_set.size();

	return 0;
}