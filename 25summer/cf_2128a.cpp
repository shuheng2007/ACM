#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		ll long long
#define		MAX_N 30
#define		MAX_T 1000

using namespace std;

int t;
int n;
ll c;
ll W[MAX_N];
int ans[MAX_T];

static int solve(int n, ll c)
{
	multiset<ll> bagset;
	int coins = 0, rnd = 0;

	for (int i = 0; i < n; i++)
		bagset.insert(W[i]);

	while (!bagset.empty())
	{
		multiset<ll> temp;

		multiset<ll>::iterator it = bagset.upper_bound(c);
		if (it == bagset.end())
			bagset.erase(--bagset.end());
		else if (it == bagset.begin()) {
			coins += (int)bagset.size();
			return coins;
		}
		else 
			bagset.erase(--it);

		for (multiset<ll>::iterator itc = bagset.begin(); itc != bagset.end(); itc++)
			temp.insert(*itc * 2);

		bagset = temp;
	}

	return coins;
}

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %lld", &n, &c);
		for (int j = 0; j < n; j++)
			scanf("%lld", W + j);
		ans[i] = solve(n, c);
	}
	for (int i = 0; i < t; i++)
		printf("%d\n", ans[i]);
	return 0;
}