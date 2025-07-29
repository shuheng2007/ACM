#define		_CRT_SECURE_NO_WARNINGS
#include	<cstdio>
#include	<vector>
#define		MAX_N 200001

using namespace std;

int n;
int T[MAX_N];

static int solve()
{
	vector<vector<int>> info1(n, vector<int>(0));
	vector<vector<int>> info2(n, vector<int>(0));
	vector<vector<int>> info[2] = { info1, info2 };
    for (int i = 0; i < n; i++)
        info[0][i].push_back(i);
	int count = 0;

	while (1) {
		count++;
		int index = (count & 1) ^ 1;
		for (int i = 0; i < n; i++) {
			auto it = info[index][i].begin();
			while (it != info[index][i].end()) {
				if (*it == T[i]) return count;
				info[!index][T[i]].push_back(*it);
				info[!index][i].push_back(*it);
				it++;
			}
			info[index][i].clear();
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &T[i]);
		T[i]--;
	}
	printf("%d\n", solve());
	return 0;
}