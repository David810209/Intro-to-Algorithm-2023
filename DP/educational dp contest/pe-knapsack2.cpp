#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi dp(105, vi(100005, -1));

vi weight(105), value(105);
int n, w;

int func(const int &idx, const int &vi)
{
    if (dp[idx][vi] != -1)
    {
        return dp[idx][vi];
    }
    if (idx == n)
    {
        return vi == 0 ? 0 : INT_MAX;
    }

    int ans = func(idx + 1, vi);
    if (value[idx] <= vi)
    {
        ans = min(ans, weight[idx] + func(idx + 1, vi - value[idx]));
    }
    return dp[idx][vi] = ans;
}

int solve(const int &v_total)
{
    for (int i = v_total; i >= 0; i--)
    {
        if (func(0, i) <= w)
            return i;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> w;
    int v_total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
        v_total += value[i];
    }
    cout << solve(v_total) << '\n';
    return 0;
}
