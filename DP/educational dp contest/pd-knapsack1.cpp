#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi dp(105, vi(100005, -1));
vi value(105), weight(105);
int n, w;
int func(const int &i, const int &wt)
{
    if (i == 0 || wt == 0)
        return 0;

    if (dp[i][wt] != -1)
    {
        return dp[i][wt];
    }
    int pre = func(i - 1, wt);
    if (weight[i] > wt)
    {
        dp[i][wt] = pre;
        return dp[i][wt];
    }
    else
    {
        dp[i][wt] = max(pre, func(i - 1, wt - weight[i]) + value[i]);
        return dp[i][wt];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    cout << func(n, w) << '\n';

    return 0;
}
