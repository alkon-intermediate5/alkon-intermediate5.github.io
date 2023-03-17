#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;
	long long twoMultiple = 1;
	do {
		twoMultiple <<= 1;
		if (N == twoMultiple - 1) {
			cout << 1 << '\n' << N;
			return 0;
		}
	} while (N >= twoMultiple);
	long long K = 2, ans1, ans2;
	ans1 = (twoMultiple / 2 - 1) - (N - twoMultiple / 2);
	ans2 = N;
	cout << K << '\n' << ans1 << '\n' << ans2;
	return 0;
}