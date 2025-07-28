#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_N 10000
#define MAX_L 1000000
#define MAX_P 1000000

using namespace std;

int N, P, L;
int A[MAX_N + 1], B[MAX_N + 1];		//把终点看成加油站

static int solve()
{
	A[N] = L;						//把终点看成加油站
	B[N] = 0;
	N++;

	priority_queue<int> que;

	int ans = 0, pos = 0, tank = P;

	for (int i = 0; i < N; i++) {
		int d = A[i] - pos;
		while (tank - d < 0) {
			if (que.empty()) return -1;
			tank += que.top();
			que.pop();
			ans++;
		}
		tank -= d;
		pos = A[i];
		que.push(B[i]);
	}
	return ans;
}

int main()
{
	cin >> N >> L >> P;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	cout << solve() << endl;
	return 0;
}