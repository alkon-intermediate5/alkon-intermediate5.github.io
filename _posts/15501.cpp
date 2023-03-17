#include <iostream>
using namespace std;

int existingArr[1000001];
int newArr[1000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> existingArr[i];
	int startIndex = 0;
	for (int i = 1; i <= n; i++) {
		cin >> newArr[i];
		if (newArr[i] == existingArr[1]) {
			startIndex = i;
		}
	}
	bool clockwise = true, counterClockwise = true;
	//반시계
	int checkCnt = 0;
	for (int i = startIndex; i > 0; i--) {
		if(newArr[i] != existingArr[1 + checkCnt]){
			counterClockwise = false;
			break;
		}
		checkCnt++;
	}
	if (counterClockwise) {
		for (int i = n; i > startIndex; i--) {
			if (newArr[i] != existingArr[1 + checkCnt]) {
				counterClockwise = false;
				break;
			}
			checkCnt++;
		}
	}
	checkCnt = 0;
	//시계
	for (int i = startIndex; i <= n; i++) {
		if (newArr[i] != existingArr[1 + checkCnt]) {
			clockwise = false;
			break;
		}
		checkCnt++;
	}
	if (clockwise) {
		for (int i = 1; i < startIndex; i++) {
			if (newArr[i] != existingArr[1 + checkCnt]) {
				clockwise = false;
				break;
			}
			checkCnt++;
		}
	}
	

	if (clockwise || counterClockwise) {
		cout << "good puzzle";
	}
	else {
		cout << "bad puzzle";
	}
	return 0;
}