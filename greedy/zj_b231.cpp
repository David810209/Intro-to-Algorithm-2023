#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            int p, b;
            cin >> p >> b;
            pq.push(make_pair(b, p));
        }

        int cost = 0;
        int cur = 0;
        while (!pq.empty())
        {
            cur += pq.top().second;
            cost = max(cost, cur + pq.top().first);
            pq.pop();
        }
        cout << cost << "\n\n";
    }

    return 0;
}
