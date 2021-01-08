//Solution
//- �ٸ������ Ǯ�̸� ���� Ǯ�����ϴ�.
//- �ڵ带 �����Ϸ��� �غ����� �����ϱ� ����� �ָ����� �н��Ͽ�
//- �ַ�� �����ϰڽ��ϴ�.

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX_PAGE 501

int K;
int vol[MAX_PAGE];
int dp[MAX_PAGE][MAX_PAGE];
int sum[MAX_PAGE];

void init() {
    cin >> K;
    for (int y = 1; y <= K; y++) {
        for (int x = y; x <= K; x++) {
            dp[y][x] = INT_MAX;
        }
    }
    for (int k = 1; k <= K; ++k) {
        cin >> vol[k];
        sum[k] = sum[k - 1] + vol[k];
    }
}

int expand(int s, int e) {
    if (dp[s][e] != INT_MAX) return dp[s][e];
    if (s == e) return dp[s][e] = 0;
    if (s + 1 == e) return dp[s][e] = vol[s] + vol[e];

    for (int k = s; k < e; ++k) {
        dp[s][e] = min(dp[s][e], expand(s, k) + expand(k + 1, e));
    }

    return dp[s][e] += sum[e] - sum[s - 1];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        cout << expand(1, K) << endl;
    }
    return 0;
}
