#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vvi dp(n + 1, vi(m + 1, 0));
    string ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while (i && j)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else
            i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
