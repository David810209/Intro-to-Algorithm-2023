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
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        int cost = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cost += (a + b);
            pq.push(a + b);
        }
        cout << cost << '\n';
    }

    return 0;
}
