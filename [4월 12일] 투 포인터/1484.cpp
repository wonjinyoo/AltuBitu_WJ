/*	
	[1484] 다이어트
*/

#include <iostream>
#include <vector>

using namespace std;

// G가 100,000보다 작거나 같으므로, 가능한 경우를 계산해서 vector 크기 정함 (50,000^2 - 49,999^2 = 99,999)
const int MAX = 50001;

void currentWeight(int g) {
	vector<int> arr(MAX, 0);
	
	// 포인터를 이용해서 차를 구할 것이기 때문에 left, right의 위치를 이렇게 정함
	// 포인터 위치 = 오른쪽으로만 이동하도록 함
	int left = 1, right = 2;
	
	// 수가 없을 때 -1을 출력하기 위해 변수 지정
	int cnt = 0;
	
	// arr 벡터에 담은 것은 1의 제곱, 2의 제곱, ... , 50000의 제곱
	// arr 벡터의 원소들끼리 차를 구해 g와 비교할 것임
	for (int i = 1; i < MAX; i++) {
		arr[i] = i * i;
	}
	
	while (left < right) {
		
		// 두 원소의 차가 g와 같으면 해당되는 값을 출력하고
		// cnt 값 하나 늘리고, right 포인터를 하나 오른쪽으로 이동시킴
		if (arr[right] - arr[left] == g) {
			cout << right << '\n';
			cnt++;
			right++;
		}
		
		// 차가 g보다 더 작으면 => 차를 늘려야 함 => right를 더 오른쪽으로
		else if (arr[right] - arr[left] < g) {
			right++;
		}
		
		// 차가 g보다 크면 => 차를 줄여야 함 => left를 하나 오른쪽으로
		else {
			left++;
		}
	}

	// 해당되는 경우가 없는 경우 -1 출력
	if (cnt == 0) {
		cout << "-1\n";
	}
}

int main() {
	int g;
	
	// 입력
	cin >> g;

	currentWeight(g);

	return 0;
}