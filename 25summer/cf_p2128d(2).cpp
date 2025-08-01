#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		MAX_T 10000
#define		MAX_N 500000
#define		ll long long

using namespace std;

int t;
int n;
int p[MAX_N];
ll ans[MAX_T];

static ll solve()
{
	ll ans = 0;
	ll* dp = new ll[n];
	dp[0] = 1;
	dp[1] = (p[1] < p[0]) ? 4 : 3;
	
	int* ldsn = new int[n];			//在所有0~i的片段中，i作为ldsn末位的数量
	ldsn[0] = 1;
	ldsn[1] = 2;

	ll* ldslen = new ll[n];
	ldslen[0] = 1;
	ldslen[1] = (p[1] < p[0]) ? 3 : 2;

	for (int i = 2; i < n; i++) {

		if (p[i] < min(p[i - 1], p[i - 2])) {
			if (p[i - 1] < p[i - 2]) {
				ldsn[i] = ldsn[i - 1] + 1;
				ldslen[i] = ldslen[i - 1] + ldsn[i];
			}
			else {
				ldsn[i] = ldsn[i - 2] + 2;
				ldslen[i] = ldslen[i - 2] + ldsn[i] + 1;
			}
		}
		else {
			if (p[i - 1] > p[i - 2]) {
				ldsn[i] = ldsn[i - 1] + 1;
				ldslen[i] = ldslen[i - 1] + ldsn[i];
			}
			else {
				ldsn[i] = ldsn[i - 2] + 2;
				ldslen[i] = ldslen[i - 2] + ldsn[i];
			}
		}

		dp[i] = dp[i - 1] + ldslen[i];
	}

	ans = dp[n - 1];
	delete[] dp;
	delete[] ldsn;
	delete[] ldslen;
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
	for(int i=0;i<t;i++)
		printf("%lld\n", ans[i]);
	return 0;
}