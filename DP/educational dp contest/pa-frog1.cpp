#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    vector<long long> dp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; ++i)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[n - 1] << '\n';
    return 0;
}
