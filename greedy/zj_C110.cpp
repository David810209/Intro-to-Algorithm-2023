#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int b1, b2, b3, b4, b5, b6;
    while (cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6)
    {
        if (b1 + b2 + b3 + b4 + b5 + b6 == 0)
            break;
        int ans = 0;
        ans += b6;

        ans += b5;
        b1 -= b5 * 11;

        ans += b4;
        b2 -= b4 * 5;

        ans += (b3 + 3) / 4;
        if (b3 % 4 == 1)
        {
            b2 -= 5;
            b1 -= 7;
        }
        else if (b3 % 4 == 2)
        {
            b2 -= 3;
            b1 -= 6;
        }
        else if (b3 % 4 == 3)
        {
            b2 -= 1;
            b1 -= 5;
        }

        if (b2 > 0)
        {
            ans += (b2 + 8) / 9;
            b2 -= 9 * ((b2 + 8) / 9);
        }

        if (b2 < 0)
            b1 += b2 * 4;
        if (b1 > 0)
            ans += (b1 + 35) / 36;
        cout << ans << '\n';
    }
    return 0;
}
