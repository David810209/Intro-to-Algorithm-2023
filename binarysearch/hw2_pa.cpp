#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll findKth(const ll &a, const ll &b, const ll &k)
{
    ll l = 1, r = k * max(a, b);

    ll ans = 0;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll count = m / a + m / b - 2 * (m / lcm(a, b));
        if (count >= k)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        cout << findKth(a, b, k) << '\n';
    }

    return 0;
}
