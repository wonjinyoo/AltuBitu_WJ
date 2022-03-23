#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 다소 무식하게 연립방정식 & 근의 공식을 사용했습니다..
void Tile(const int& R, const int& B) {

	int res1 = (R + 4) / 2;
	int res2 = R + B;

	int x = (res1 + sqrt(res1 * res1 - 4 * res2)) / 2;
	int y = res1 - x;

	cout << max(x, y) << ' ' << min(x, y);
}

int main() {
	int R, B;
	cin >> R >> B;
	Tile(R, B);
	return 0;
}
