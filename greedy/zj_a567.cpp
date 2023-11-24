#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
// #define int long long
#define d first
#define p second

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        vector<pii> hw(n);
        for (int i = 0; i < n; i++)
        {
            cin >> hw[i].d >> hw[i].p;
        }

        sort(all(hw));
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (hw[i].d > pq.size())
            {
                ans += hw[i].p;
                pq.push(hw[i].p);
            }
            else if (hw[i].d == pq.size() && hw[i].p > pq.top())
            {
                ans -= pq.top();
                pq.pop();
                ans += hw[i].p;
                pq.push(hw[i].p);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
