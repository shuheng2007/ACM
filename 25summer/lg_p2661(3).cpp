#define		_CRT_SECURE_NO_WARNINGS
#include	<cstdio>
#include	<algorithm>
#include	<vector>
#define		MAX_N 200001

using namespace std;

int n;
int T[MAX_N];

struct vertex
{
	int num;
	vertex* to;
	int viewed = 0;
};

static int solve()
{
	int min_count = n;
	vertex* array = new vertex[n];

	for (int i = 0; i < n; i++) {
		vertex* ap = array + i;
		ap->num = i;
        ap->to = &array[T[i]];
	}

	for (int i = 0; i < n; i++) {

		vertex* pt = array + i;
		if (pt->viewed) continue;
		else pt->viewed = 1;

		int count = n;
		vector<vertex*> vp;
		vp.push_back(pt);

		while (pt = pt->to) {
			if (pt->viewed) {
				for (vertex** it = &vp[0]; it < &vp[0] + vp.size(); it++)
					if (*it == pt) {
						count = vp.size() - (it - &vp[0]);
						break;
					}
				break;
			}
			vp.push_back(pt);
			pt->viewed = 1;
		}

		min_count = min(min_count, count);
	}
	delete[] array;
	return min_count;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", T + i);
		(*(T + i))--;
	}
	printf("%d", solve());
	return 0;
}