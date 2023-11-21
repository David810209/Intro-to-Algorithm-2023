#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ll long long
const int N = 205;
vvi dp(N, vi(N, -1));

vvi cut(N, vi(N));

vi x(N);

ll func(const int &l, const int &r)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    for (int i = l; i <= r; ++i)
    {
        ll tmp = abs((x[i] - x[l - 1]) - (x[r + 1] - x[i])) + func(l, i - 1) + func(i + 1, r);
        if (dp[l][r] == -1 || tmp < dp[l][r])
        {
            dp[l][r] = tmp;
            cut[l][r] = i;
        }
    }
    return dp[l][r];
}
vi ans;

void path(const int &l, const int &r)
{
    if (l > r)
        return;
    ans.push_back(cut[l][r]);
    path(l, cut[l][r] - 1);
    path(cut[l][r] + 1, r);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    func(1, n - 1);
    path(1, n - 1);
    cout << dp[1][n - 1] << '\n';
    for (auto &x : ans)
    {
        cout << x << ' ';
    }
    return 0;
}
