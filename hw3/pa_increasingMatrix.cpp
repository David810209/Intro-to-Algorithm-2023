#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef vector<int> vi;
struct Element
{
    int value, i, j;

    bool operator>(const Element &other) const
    {
        return value > other.value;
    }
};

int ans(const vector<int> &a, const vector<int> &b, int k)
{
    int n = a.size();
    int m = b.size();
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({a[i] * a[i] + a[i] * b[0] + b[0] * b[0], i, 0});
    }

    int kSmallest = 0;
    int xorResult = 0;

    while (kSmallest < k && !pq.empty())
    {
        Element current = pq.top();
        pq.pop();
        kSmallest++;
        xorResult ^= current.value;

        int i = current.i;
        int j = current.j;

        if (j < m - 1)
        {
            pq.push({a[i] * a[i] + a[i] * b[j + 1] + b[j + 1] * b[j + 1], i, j + 1});
        }
    }

    return xorResult;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cout << ans(a, b, k) << '\n';
    return 0;
}
