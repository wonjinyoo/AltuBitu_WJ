#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, string> v1, pair<int, string> v2) {
	if (v1.first != v2.first)
		return v1.first > v2.first;
	if (v1.second.length() != v2.second.length())
		return v1.second.length() > v2.second.length();
	return v1.second < v2.second;  // 알파벳 순서대로
}

int main() {
	map<string, int> word;
	int n, len; // 단어 개수, 단어 길이 기준
	cin >> n >> len;
	while (n--) {  // 이렇게 쓰는 거 익숙해지자
		string w;
		cin >> w;
		if (w.length() < len) continue;
		word[w]++;
	}

	vector<pair<int, string>> wrd;  // vector랑 pair 같이 쓰는 거
	for (auto iter = word.begin(); iter != word.end(); iter++) {
		wrd.push_back(make_pair(iter->second, iter->first));  // make_pair 쓰지 않으면 안됨?
	}

	sort(wrd.begin(), wrd.end(), cmp);

	for (int i = 0; i < wrd.size();i++) {
		cout<<wrd[i].second<<'\n'; //참고: map에서 first=key, second=value
	}
	return 0;
}