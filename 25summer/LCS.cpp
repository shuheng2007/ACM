#include <iostream>
#include <algorithm>
constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;

using namespace std;

int n, m;
char s[MAX_N], t[MAX_M];

int dp[MAX_N + 1][MAX_M + 1];

static void solve()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;
	solve();
	cout << dp[n][m];
	return 0;
}