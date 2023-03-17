#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[50][50];
vector<pair<int, int>> order;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (i == 0) {
				order.push_back({ arr[i][j], j });
			}
		}
	}
	sort(order.begin(), order.begin() + M, cmp);
	for (int i = 0; i < N; i++) {
		bool escape = false;
		//�� �� �ּڰ� �� ���� ���� Ȯ��
		int minVal = *min_element(arr[i], arr[i] + M);
		if (minVal % M != 1) {
			ans = 0;
			break;
		}
		//�� ���� �ּڰ����� ���������� 1�� �����ϴ��� Ȯ��
		for (int j = 0; j < M; j++) {
			if (arr[i][order[j].second] != minVal + j) {
				ans = 0;
				escape = true;
				break;
			}
		}
		if (escape)
			break;
	}
	cout << ans;
	return 0;
}