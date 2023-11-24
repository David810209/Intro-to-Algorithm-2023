#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int arr[N];
int seg[N * 4];

void build(const int &node, const int &l, const int &r)
{
    if (l == r)
    {
        seg[node] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    int leftnode = node * 2 + 1;
    int rightnode = node * 2 + 2;
    build(leftnode, l, m);
    build(rightnode, m + 1, r);

    seg[node] = seg[leftnode] * seg[rightnode];
}

void upd(const int &node, const int &l, const int &r, const int &idx, const int &vi)
{
    if (l == r)
    {
        arr[idx] = vi;
        seg[node] = vi;
        return;
    }
    int m = (l + r) / 2;
    int leftnode = node * 2 + 1;
    int rightnode = node * 2 + 2;
    if (idx >= l && idx <= m)
        upd(leftnode, l, m, idx, vi);
    else
        upd(rightnode, m + 1, r, idx, vi);
    seg[node] = seg[leftnode] * seg[rightnode];
}

int qry(const int &node, const int &l, const int &r, const int &ql, const int &qr)
{
    if (ql > r || qr < l)
        return 1;
    if (ql <= l && qr >= r)
        return seg[node];
    if (l == r)
        return seg[node];
    int m = (l + r) / 2;
    int leftnode = node * 2 + 1;
    int rightnode = node * 2 + 2;
    if (ql > m)
        return qry(rightnode, m + 1, r, ql, qr);
    else if (qr < m)
        return qry(leftnode, l, m, ql, qr);
    return qry(rightnode, m + 1, r, ql, qr) * qry(leftnode, l, m, ql, qr);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    while (cin >> n >> q)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            if (arr[i] > 0)
                arr[i] = 1;
            else if (arr[i] < 0)
                arr[i] = -1;
        }

        build(0, 0, n - 1);
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'C')
            {
                int idx, vi;
                cin >> idx >> vi;
                if (vi > 0)
                    vi = 1;
                else if (vi < 0)
                    vi = -1;
                upd(0, 0, n - 1, idx - 1, vi);
            }
            else
            {
                int ql, qr;
                cin >> ql >> qr;
                int x = qry(0, 0, n - 1, ql - 1, qr - 1);
                if (x > 0)
                    cout << '+';
                else if (x == 0)
                    cout << '0';
                else
                    cout << '-';
            }
        }
        cout << '\n';
    }

    return 0;
}
