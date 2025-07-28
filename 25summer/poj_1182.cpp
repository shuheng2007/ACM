#define		_CRT_SECURE_NO_WARNINGS
#include	<cstdio>
#include	<algorithm>
#include	<queue>
#include	<vector>
#define		MAX_N 50000
#define		MAX_K 100000

//using namespace std;

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];
int par[MAX_N], rank[MAX_N];

void init(int n)
{
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rank[x] < rank[y])
		par[x] = y;
	else {
		par[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

static int solve()
{
	int ans = 0;
	int t, x, y;
	init(N * 3);
	for (int i = 0; i < K; i++) {
		t = T[i], x = X[i] - 1, y = Y[i] - 1;
		if ((t != 1 && t != 2) || (x < 0 || x >= N) || (y < 0 || y >= N)) {
			ans++;
			continue;
		}
		if (t == 1) {
			if (same(x, y + N) || same(x, y + N * 2))
				ans++;
			else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + N * 2, y + N * 2);
			}
		}
		else {
			if (same(x, y) || same(x, y + N * 2))
				ans++;
			else {
				unite(x, y + N);
				unite(x + N, y + N * 2);
				unite(x + N * 2, y);
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++)
		scanf("%d %d %d", &T[i], &X[i], &Y[i]);
	printf("%d\n", solve());
	return 0;
}