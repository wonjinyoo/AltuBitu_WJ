#include <iostream>
#include <vector>

using namespace std;

int GroupCheck(string str) {
	int length = str.length();
	int cnt = 0;
	// 이런 체크 배열 사용하는 거 익숙해지자, 그리고 인덱스 조심!!
	bool alph[27] = { false, };

	// 맨처음 들어오는 알파벳은 true
	alph[(int)str[0] - 97] = true;

	for (int i = 1; i < length; i++) {
		
		int x = (int)str[i] - 97;

		// (1) 연속해서 들어옴 : 그룹 단어
		if (str[i] == str[i - 1]) continue;

		// (2) 연속해서 들어오는 거 x & 처음 들어올 경우 : 그룹 단어 가능성 O
		else if (alph[x] == false) {
			alph[x] = true;
		}
		// (3) 연속해서 X, 처음 X : 그룹단어 아님
		else {
			cnt++;
			break;
		} 
	}

	return cnt;
}


int main() {
	int n, k = 0;
	cin >> n;
	vector<string> wrd(n);
	
	for (int i = 0; i < n; i++) {
		cin >> wrd[i];
		k += GroupCheck(wrd[i]);
	}

	// k = 그룹 단어 아닌 단어 개수임
	cout << n - k;

	return 0;
}