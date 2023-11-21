#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c(n + 1);
    vvi dp(n + 1, vi(3));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';

    return 0;
}
