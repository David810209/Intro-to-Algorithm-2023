#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pii pair<int, int>

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        vector<pii> interval(n);
        for (int i = 0; i < n; i++)
        {
            cin >> interval[i].first >> interval[i].second;
        }

        sort(all(interval), [](const pii &a, const pii &b)
             { 
                if(a.second != b.second)return a.second< b.second;
                else  return a.first< b.first; });
        sort(all(p));

        for (int i = 0; i < n; i++)
        {
            for (auto j = 0u; j < p.size(); j++)
            {
                if (interval[i].first <= p[j] && p[j] <= interval[i].second)
                {
                    p.erase(p.begin() + j);
                    break;
                }
            }
        }

        cout << (p.empty() ? "Yes\n" : "No\n");
    }

    return 0;
}

/*


7
3
4 3 5
3 5
5 6
2 3
3
2 6 6
3 5
5 6
2 3
4
10 11 8 5
1 8
4 5
8 11
10 12
3
3 4 99
1 4
3 100
87 87
3
1 2 3
3 4
2 4
1 4
3
10 2 8
10 10
1 10
7 9
1
100
101 102
*/
