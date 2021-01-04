#include <iostream>
#include <cstring>
using namespace std;
/*
	dp��� �𸣰� Ǯ���� �� ������� ����
	ó���� bfs �������� �����ϴµ� �ڲ� �������̽��� ����
	��� ��츦 Ž�����־�� �Ѵٰ� �ν��ϰ� �� -> UP-DOWN ������� ����
*/
int m, n;
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int y_ar[4] = {0, 0, -1, 1};
int x_ar[4] = { 1,-1,0,0 };

int solved(int y, int x) {
	if (y == 1 && x == 1)
		return 1;
	int &ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + y_ar[i];
		int nx = x + x_ar[i];
		if (ny >= 1 && ny <= m && nx >= 1 && nx <= n) {
			if (arr[y][x] < arr[ny][nx]) {
				ret += solved(ny, nx);
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solved(m,n) << endl;

	/*
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
	*/
	return 0;
}