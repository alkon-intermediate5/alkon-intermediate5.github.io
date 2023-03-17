#include <iostream>
#include <algorithm>
using namespace std;

int arrOdd[150001];
int arrEven[150001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	bool isPossible = true;
	int oddCur = 1, evenCur = 1;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0)
			cin >> arrEven[evenCur++];
		else
			cin >> arrOdd[oddCur++];
	}
	arrEven[0] = 0;
	arrOdd[0] = 0;
	sort(arrOdd + 1, arrOdd + oddCur);
	sort(arrEven + 1, arrEven + evenCur);
	for (int i = 1; i <= N / 2 - 1; i++) {
		if (!(arrOdd[i] < arrEven[i] && arrEven[i] < arrOdd[i + 1]))
			isPossible = false;
		if (!(arrEven[i] < arrOdd[i + 1] && arrOdd[i + 1] < arrEven[i + 1]))
			isPossible = false;
	}
	if (N % 2 == 1) {
		if (!(arrOdd[evenCur - 1] < arrEven[evenCur - 1] && arrEven[evenCur - 1] < arrOdd[evenCur]))
			isPossible = false;
	}
	cout << (isPossible == true ? "YES" : "NO");
	return 0;
}