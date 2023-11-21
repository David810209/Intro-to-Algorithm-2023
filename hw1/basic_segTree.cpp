#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl '\n'
#define all(x) x.begin(), x.end()

const int N = 2e5 + 5;

int arr[N];
int seg[N << 2];
int qry(const int &node, const int &l, const int &r, const int &qry_l, const int &qry_r, const int &k)
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
    return qry(left_node, l, m, qry_l, qry_r, k) + qry(right_node, m + 1, r, qry_l, qry_r, k);
}

void update(const int &node, const int &l, const int &r, const int &idx, const int &v)
{
    if (l == r)
    {
        arr[idx] = v;
        seg[node] = v;
        return;
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    if (idx >= l && idx <= m)
        update(left_node, l, m, idx, v);
    else
        update(right_node, m + 1, r, idx, v);
    seg[node] = seg[left_node] + seg[right_node];
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
    seg[node] = seg[left_node] + seg[right_node];
}
void print_seg(const int &n)
{
    for (int i = 0; i < n * 4; ++i)
    {
        cout << seg[i] << ' ';
    }
    cout << endl;
}
void print_arr(const int &n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    build(0, 0, n - 1);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, v;
            cin >> idx >> v;
            update(0, 0, n - 1, idx - 1, v);
            print_arr(n);
            print_seg(n);
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << qry(0, 0, n - 1, l - 1, r - 1, k) << '\n';
        }
    }
    return 0;
}
