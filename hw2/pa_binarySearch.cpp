#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll findKthTerm(ll a, ll b, ll k)
{
    ll low = 1, high = k * max(a, b), result = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll count = mid / a + mid / b - 2 * (mid / lcm(a, b));

        if (count >= k)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        cout << findKthTerm(a, b, k) << '\n';
    }

    return 0;
}
