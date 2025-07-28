#include <iostream>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int n;
int a[MAX_N];
int dp[MAX_N];

static int solve()
{
	int res = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = solve();
	cout << res << endl;
	return 0;
}