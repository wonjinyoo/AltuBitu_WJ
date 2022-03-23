// 틀린 코드입니다..! 피드백 해주시면 참고하여 수정하겠습니다!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*	제 시도는 일단 
	1. 먼저 '개수' 충족하는 문자열을 모두 만들고 (조합 이용하여)
*	2. 그 문자열에 모음이 하나라도 없으면 안된다는 조건을 확인하여 걸러내는 작업을 하고 싶었는데요..
*	next_permutation을 사용해보려고 했는데 아직 익숙치가 않아서.. 잘 모르겠습니다..
*/


int main() {
	int l, c; 
	// l = 암호 길이, c =문자 종류 개수
	cin >> l >> c;
	// 문자 종류 담는 벡터
	vector<char> ch(c);
	
	// permutation 사용 위한 벡터
	vector<int> temp(c);
	// 결과 출력 위한 벡터
	vector<char> res;

	// 입력
	for (int i = 0; i < c; i++) cin >> ch[i];

	// permutation 위해서, temp 벡터에 l개 만큼 1을 넣어준다
	for (int i = 0; i < l; i++) temp.push_back(1);
	for (int i = l; i < c; i++) temp.push_back(0);

	// 정렬해야
	sort(ch.begin(), ch.end());

	do {
		for (int i = 0; i < c; i++) {
			// 모음 개수
			int v_cnt = 0;
			if (temp[i] == 1) {
				res.push_back(ch[i]);
				if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') v_cnt++;
				
				if (i == c - 1 && v_cnt < 1) continue;
				else if (i == c - 1 && v_cnt >= 1) {
					for (int j = 0; j < l; j++) cout << res[j];
				}
				else continue;
			}
		}
		cout << '\n';
	} while (next_permutation(temp.begin(), temp.end()));

	return 0;
}
