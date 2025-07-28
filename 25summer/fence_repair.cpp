#include <iostream>
#include <algorithm>
#include <queue>
//#include <functional>
//#include <vector>
#define MAX_N 20000

using namespace std;

int N;
int L[MAX_N];

static int solve()
{
	priority_queue<int, vector<int>, greater<int>> que;

	int a, b;
	int ans = 0;

	if (N == 1) return 0;
	for (int i = 0; i < N; i++) que.push(L[i]);
	while (que.size()>=2) {
		a = que.top(), que.pop();
		b = que.top(), que.pop();
		ans += a + b;
		que.push(a + b);
	}
	return ans;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	cout << solve() << endl;
	return 0;
}