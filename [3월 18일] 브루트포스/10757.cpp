#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Add(string A, string B) {
	stack<int> a, b, res;

	for (int i = 0; i < A.length(); i++) {
		//문자를 정수로 바꾸기
		int x = A[i] - '0'; 
		// 계산하기 위해 스택에 넣기 (일의 자리부터)
		a.push(x);
	}

	for (int i = 0; i < B.length(); i++) {
		int y = B[i] - '0';
		// 계산하기 위해 스택에 넣기 (일의 자리부터)
		b.push(y);
	}

	// 스택 이용하여 계산
	// 덧셈 시 올려 더해줘야되는 수 저장
	int up = 0; 
	
	// 두 수 중에 더 큰 자리수를 cnt에 저장
	int cnt = max(A.length(), B.length());
	
	while (cnt--) {
		// 만약 한 스택이 다 비면 남은 스택만 혼자 계산해주면 됨
		if (a.empty() && !b.empty()) {
			while (!b.empty()) {
				res.push((b.top() + up) % 10);
				up = (b.top() + up) / 10;
				b.pop();
			}
			break;
		}

		else if (b.empty() && !a.empty()) {
			while (!a.empty()) {
				res.push((a.top() + up) % 10);
				up = (a.top() + up) / 10;
				a.pop();
			}
			break;
		}

		else if (a.empty() && b.empty()) break;

		// 계산
		res.push((a.top() + b.top() + up) % 10);
		up = (a.top() + b.top() + up) / 10;
		a.pop();
		b.pop();
	}

	// 결과 출력
	if (up != 0) cout << up;
	while (!res.empty()) {
		cout << res.top();
		res.pop();
	}
}

int main() {
	string A, B;
	cin >> A >> B;
	Add(A, B);
	return 0;
}
