#include <bits/stdc++.h>

using namespace std;
#define ll long long

typedef vector<int> vi;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi p(n), pre(n), q(m);
    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (i == 0)
            pre[i] = p[i];
        else
            pre[i] = pre[i - 1] + p[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }

    int pos = 0;

    for (int i = 0; i < m; i++)
    {
        int target = q[i];
        if (pos != 0)
            target += pre[pos - 1];
        if (target > pre[n - 1])
            target -= pre[n - 1];
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (target <= pre[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        pos = l + 1;
        pos %= n;
    }
    cout << pos << '\n';

    return 0;
}
