#include	<cstdio>
#include	<algorithm>
#define		MAX_N 200001

using namespace std;

int n;
int T[MAX_N];

int find(int x)
{
	int ans = 1;
	int temp = x;
	while (T[x] != temp && ans < n) {
		x = T[x];
		ans++;
	}
	return ans;
}

static int solve()
{
	int round = n;
	for (int i = 1; i <= n; i++)
		round = min(round, find(i));
	return round;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &T[i]);
	printf("%d", solve());
	return 0;
}