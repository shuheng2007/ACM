#define		_CRT_SECURE_NO_WARNINGS
#include	<bits/stdc++.h>
#define		MAX_T 10000
#define		MAX_N 100000

using namespace std;

int t;
int n;
int p[MAX_N];
vector<string> ans;

static string solve(int n)
{
	string list;
	stack<int> q;
	
	int dirc = 1;		//0表示递减，1表示递增
	int cnt = 0;
	int* lpt = p;
	int* rpt = p + n - 1;
	q.push(0);

	while (lpt <= rpt) {
		int q_last = q.top();
		if ((dirc && max(*lpt, *rpt) < q_last) || (!dirc && min(*lpt, *rpt) > q_last) || cnt == 4) {
			dirc = !dirc;
			cnt = min(cnt, 1);
		}
		if (dirc ^ (*lpt < *rpt)) {
			list.push_back('L');
			q.push(*lpt);
			lpt++;
		}
		else {
			list.push_back('R');
			q.push(*rpt);
			rpt--;
		}
		cnt++;
	}
	return list;
}

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", p + j);
		ans.push_back(solve(n));
	}
	for (int i = 0; i < t; i++)
		printf("%s\n", ans[i].c_str());
	return 0;
}