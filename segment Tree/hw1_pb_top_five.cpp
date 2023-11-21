#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define endl '\n'
#define all(x) x.begin(), x.end()

const int N = 2e5 + 5;

int arr[N];

struct Node
{
    vi five;
} seg[N << 2];

void maintain(const int &node, const int &l, const int &r)
{
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    vi a, b;
    if (left_node < (N << 2))
        a = seg[left_node].five;
    if (right_node < (N << 2))
        b = seg[right_node].five;
    seg[node].five.resize(a.size() + b.size());
    merge(all(a), all(b), seg[node].five.begin());
    seg[node].five.resize(min((int)seg[node].five.size(), 5));
}

vi qry(const int &node, const int &l, const int &r, const int &qry_l, const int &qry_r)
{
    if (qry_l > r || qry_r < l)
    {
        return {};
    }
    else if (l == r)
    {
        return seg[node].five;
    }
    else if (qry_l <= l && r <= qry_r)
    {
        return seg[node].five;
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    auto a = qry(left_node, l, m, qry_l, qry_r);
    auto b = qry(right_node, m + 1, r, qry_l, qry_r);
    vi ret(a.size() + b.size());
    merge(all(a), all(b), ret.begin());
    ret.resize(min((int)ret.size(), 5));
    return ret;
}

void update(const int &node, const int &l, const int &r, const int &idx, const int &v)
{
    if (l == r)
    {
        arr[idx] = v;
        seg[node].five[0] = v;
        return;
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    if (idx <= m)
        update(left_node, l, m, idx, v);
    else
        update(right_node, m + 1, r, idx, v);
    maintain(node, l, r);
}

void build(const int &node, const int &l, const int &r)
{
    if (l == r)
    {
        seg[node].five.resize(1);
        seg[node].five[0] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    build(left_node, l, m);
    build(right_node, m + 1, r);
    maintain(node, l, r);
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
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            auto ans = qry(0, 0, n - 1, l - 1, r - 1);
            cout << ans[k - 1] << '\n';
        }
    }
    return 0;
}
