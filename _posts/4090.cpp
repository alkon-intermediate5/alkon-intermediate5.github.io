#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string X;
	do {
		cin >> X;
		if (X == "0")
			break;
		int test = stoi(X);
		bool isFound = false;
		while (true) {
			string test_str = to_string(test);
			sort(test_str.begin(), test_str.end());
			for (int i = 2; i * i <= test; i++) {
				if (test % i != 0) continue;
				string cur = to_string(i) + to_string(test / i);	//a, b는 v의 약수
				sort(cur.begin(), cur.end());
				if (test_str == cur) {
					isFound = true;
					cout << test << '\n';
					break;
				}
			}
			if (isFound)
				break;
			test++;
		}
	} while (true);
	return 0;
}