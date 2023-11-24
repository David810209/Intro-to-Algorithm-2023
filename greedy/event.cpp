#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
// #define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<pii> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i].first >> time[i].second;
    }

    sort(all(time), [](const pii &a, const pii &b)
         {
        if(a.second != b.second)return a.second < b.second;
        else return a.first < b.first; });

    int ans = 1;
    int end = time[0].second;
    for (int i = 1; i < n; i++)
    {
        if (end < time[i].first)
        {
            ans++;
            end = time[i].second;
        }
    }
    cout << ans << '\n';

    return 0;
}
