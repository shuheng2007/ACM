#include	<cstdio>
#define		MAX_N 100000
#define		MAX_M 200000

int n, m;
int edges[MAX_M][2];
int par[MAX_N], rank[MAX_N];

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

static int solve()
{
	int x, y;
	int group_num = n;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		if (edges[i][0] == edges[i][1])
			continue;
		x = find(edges[i][0]);
		y = find(edges[i][1]);
		if (x != y) {
			if (rank[x] < rank[y])
				par[x] = y;
			else {
				par[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
			group_num--;
		}
	}
	return group_num;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &edges[i][0], &edges[i][1]);
	printf("%d\n", solve());
	return 0;
}