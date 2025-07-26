#include <iostream>
#include <algorithm>
constexpr int MAX_N = 100;
constexpr int MAX_W = 10000;

using namespace std;

int n, W;
int w[MAX_N], v[MAX_N];

int dp[MAX_N + 1][MAX_W + 1];

static void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i])
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> W;
    solve();
    cout << dp[n][W] << endl;
}

