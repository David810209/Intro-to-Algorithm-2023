#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define int long long

int n, m;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vvi v(n, vi(m));
    vvi dp(n, vi(m, INT_MIN));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 2 * v[i][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + v[i][j]);
            if (i > 0 && j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 4 * v[i][j]);
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}

/*
3 4
3 1 4 1
5 9 2 6
5 3 5 8


*/
