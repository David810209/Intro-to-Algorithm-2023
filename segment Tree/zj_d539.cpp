#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;

int arr[N];
int seg[N << 2];
int qry(const int &node, const int &l, const int &r, const int &qry_l, const int &qry_r)
{
    if (qry_l > r || qry_r < l)
    {
        return 0;
    }
    else if (l == r)
    {
        return seg[node];
    }
    else if (qry_l <= l && r <= qry_r)
    {
        return seg[node];
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    if (qry_r <= m)
        return qry(left_node, l, m, qry_l, qry_r);
    else if (qry_l > m)
        return qry(right_node, m + 1, r, qry_l, qry_r);
    return max(qry(left_node, l, m, qry_l, qry_r), qry(right_node, m + 1, r, qry_l, qry_r));
}

void build(const int &node, const int &l, const int &r)
{
    if (l == r)
    {
        seg[node] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    build(left_node, l, m);
    build(right_node, m + 1, r);
    seg[node] = max(seg[left_node], seg[right_node]);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> q;

    build(0, 0, n - 1);

    while (q--)
    {

        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        cout << qry(0, 0, n - 1, l - 1, r - 1) << '\n';
    }
    return 0;
}
