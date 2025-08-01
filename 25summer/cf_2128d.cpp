#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		MAX_T 10000
#define		MAX_N 500000
#define		ll long long

//TLE
// /(ㄒoㄒ)/~~
using namespace std;

int t;
int n;
int p[MAX_N];
ll ans[MAX_T];

static ll solve()
{
	ll ans;
	int l = 2;

	int* ldsdp1 = new int[n];
	int* ldsdp2 = new int[n];
	int* ldsdp[2] = { ldsdp1,ldsdp2 };
	for (int i = 0; i < n - 1; i++) {
		ldsdp[0][i] = 1;
		ldsdp[1][i] = (p[i + 1] < p[i]) ? 2 : 1;
	}

	ll* dp1 = new ll[n];
	ll* dp2 = new ll[n];
	ll* dp[2] = { dp1,dp2 };
	dp[0][n - 1] = 1;
	for (int i = 0; i < n - 1; i++) {
		dp[0][i] = 1;
		dp[1][i] = 2 + ldsdp[1][i];
	}

	int ptr = 1;
	while (l < n) {

		ptr = !ptr;

		for (int s = 0; s < n - l; s++) {
			ldsdp[ptr][s] = ldsdp[!ptr][s] + ldsdp[!ptr][s + 1] - ldsdp[ptr][s + 1];
			dp[ptr][s] = dp[!ptr][s] + dp[!ptr][s + 1] - dp[ptr][s + 1] + ldsdp[ptr][s];
		}

		l++;
	}

	ans = dp[ptr][0];

	delete[] ldsdp1;
	delete[] ldsdp2;
	delete[] dp1;
	delete[] dp2;

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
		printf("%lld\n", ans[i]);
	}
	return 0;
}