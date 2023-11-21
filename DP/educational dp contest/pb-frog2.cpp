#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), dp(n, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i - j >= 0)
                dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
