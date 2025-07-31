#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		MAX_T 10000
#define		MAX_N 200000
#define		MAX_V 1e9 + 1
#define		ll long long

using namespace std;

int t;
int n;
ll b[MAX_N];
bool ans[MAX_T];

static bool solve(int n)
{
	ll minv = MAX_V;
	for (ll* ptr = b; ptr < b + n - 1; ptr++) {		//遍历到倒数第二个元素
		minv = *ptr;
		bool found_small = false;
		for (ll* ptr2 = ptr; ptr2 < b + n; ptr2++) {
			if (*ptr2 >= 2 * minv)
				return false;
			else if (*ptr2 < minv) {
				ptr = ptr2 - 1;
				found_small = true;
				break;
			}
		}
		if (!found_small)
			return true;
	}
	return true;
}

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%lld", b + j);
		ans[i] = solve(n);
	}
	for (int i = 0; i < t; i++)
		printf(ans[i] ? "yes\n" : "no\n");
	return 0;
}