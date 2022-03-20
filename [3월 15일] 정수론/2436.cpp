/* 오류가 나는 틀린 코드입니다..!! */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//  1. 출력되어야 하는 정수 두 개(A, B)의 곱 = 입력 되는 두 정수(a, b)의 곱
//  2. 출력되어야 하는 정수를 작은 순서대로 A, B라고 했을 때, B는 A + a * n 꼴 (a는 A,B의 최대공약수, n은 자연수)
//  이런 특징(?)을 기반으로 코드를 작성했는데 여러 문제점이 있었습니다..
//     -> 반복문의 종료 조건을 어떻게 해야할지 잘 모르겠다는 점.. (멋대로 지정했습니다..)
//     -> 그러다보니 입력되는 수가 클 때는 연산이 너무 많아서 시간이 어마무시하게 오래 걸리는 거 같습니다..
//     -> 무엇보다도 제가 맘대로 생각한 위의 2번 조건이 애초에 맞는 것인지도 잘 모르겠습니다...
//   :: 제가 생각한 접근 방식으로 이 코드가 소생 가능할까요..? 워낙 코드가 드러워서요.....
//      그치만 다른 방법도 좋습니다!! 어떻게든 피드백 주시면 감사하겠습니다!!


void cd(const int &a, const int &b) {
	// 합이 최소인 거 찾기 위해 벡터에 가능한 쌍들을 담기 위함
	vector<pair<int, int>> v;

	// 반복문 종료 조건을 어떻게 지정할 수 있는 걸까요..?
	for (int i = 1; i <= sqrt(b); i++) {  
		int A = a * i;
		for (int j = 1; j <= sqrt(b); j++) {
			if (j % a != 0) {
				int B = A + a * j;
				if (A * B == a * b) {
					// 일단 최소합 이외 조건 만족시키는 거 넣기
					v.push_back({ A, B });  
					break;
				}
			}
			else break;
		}

	}


	// 최소합 조건 만족시키는 쌍을 찾기 위해
	// min의 기준을 뭘로 잡아야할지..? 너무 마구잡이 기준임
	int min = a + b;  
	int index = 0;
	for (int i = 0; i < v.size(); i++) {
		int sum = v[i].first + v[i].second;
		if (sum < min) {
			min = sum;
			index = i;
		}
	}
	cout << v[index].first << ' ' << v[index].second;
}

int main() {
	int a, b;
	cin >> a >> b;
	cd(a, b);
	return 0;
}