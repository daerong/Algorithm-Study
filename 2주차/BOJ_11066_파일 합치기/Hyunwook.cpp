#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int t, k;
int arr[501] = { 0, };
int dp[501][501] = { 0, };

int solved(int s, int e) {
	if (s == e) return 0;
	else if (s + 1 == e) return arr[e] - arr[e - 2];

	int &ret = dp[s][e];
	if (ret != -1)
		return ret;
	ret = 1000000000;
	for (int i = s; i <= e; i++) {
		ret = min(ret, solved(s, i) + solved(i + 1, e) + arr[e] - arr[s-1]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			arr[i] = arr[i] + arr[i - 1];
		}

		cout << solved(1,k) << "\n";

	}

	

	return 0;
}


/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//(int)2e9;
int sum[501] = { 0 };
int arr[501] = { 0, };
int dp[501][501] = { 0, };
int t = 0, k = 0;
int result = 0;
int main() {
cin >> t;

while (t--) {
cin >> k;
result = 0;
for (int i = 1; i <= k; i++) {
cin >> arr[i];
sum[i] = sum[i - 1] + arr[i];
}

for (int i = 1; i < k ; i++) { // 1����~ k-1 ���� �ݺ� �밢���� ����
for (int j = 1; j + i <= k; j++) { //  ���� ��Ÿ�� j����
int v = j + i;    //  ������ ǥ��
dp[j][v] = (int)2e9;  // 2*10^9

for (int u = j; u < j + i; u++) // �� �������� �¿� �Ϸ� �������鼭 �� ���ϱ� ���� �ݺ��� j���� i�� �ݺ�
dp[j][v] = min(dp[j][v], dp[j][u] + dp[u + 1][v] + sum[j + i] - sum[j - 1]);
//������ ��ġ ���� -> min(������,  �¿� �Ʒ��� ������ ������ �� + i��ŭ�� sum ���� ����)
}

}
for (int i = 1; i <= k; i++) {
for (int j = 1; j <= k; j++)
cout << dp[i][j] << ' ';
cout << endl;
}
cout << dp[1][k] << endl;

}
return 0;
}
*/