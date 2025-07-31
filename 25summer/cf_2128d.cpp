#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		MAX_T 10000
#define		MAX_N 500000

using namespace std;

int t;
int n;
int p[MAX_N];
int ans[MAX_T];

static int lds(int s, int l)
{
	if (l == 0) return 1;

	int* dp = new int [l + 1];
	int ans;

	dp[0] = 1;
	dp[1] = (p[s + 1] < p[s]) ? 2 : 1;

	for (int i = 2; i <= l; i++) {
		if (p[s + i] < min(p[s + i - 1], p[s + i - 2]))
			dp[i] = max(dp[i - 1], dp[i - 2]) + 1;
		else
			dp[i] = ((p[s + i - 1] > p[s + i - 2]) ? dp[i - 1] : dp[i - 2]) + 1;
	}

	ans = dp[l];
	delete[] dp;
	return ans;
}

static int solve()
{
	int ans;
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[n - i];

	dp[n - 1][0] = 1;
	for (int i = 0; i < n - 1; i++) {
		dp[i][0] = 1;
		dp[i][1] = 2 + lds(i, 1);
	}

	for (int l = 2; l < n; l++)
		for (int s = 0; s < n - l; s++)
			dp[s][l] = dp[s][l - 1] + dp[s + 1][l - 1] - dp[s + 1][l - 2] + lds(s, l);

	ans = dp[0][n-1];
	for (int i = 0; i < n; i++)
		delete[]dp[i];
	delete[]dp;
	return ans;
}

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", p + j);
		ans[i] = solve();
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}