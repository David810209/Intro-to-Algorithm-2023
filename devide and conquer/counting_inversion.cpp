#include <bits/stdc++.h>

using namespace std;
#define ll long long

typedef vector<int> vi;
ll total = 0;

void merge(vi &arr, const int &l, const int &m, const int &r)
{
    int l_size = m - l + 1;
    int r_size = r - m;
    vi vl(l_size), vr(r_size);

    for (int i = 0; i < l_size; i++)
    {
        vl[i] = arr[l + i];
    }
    for (int i = 0; i < r_size; i++)
    {
        vr[i] = arr[m + i + 1];
    }

    int l_idx = 0, r_idx = 0, idx = l;
    while (l_idx < l_size && r_idx < r_size)
    {
        if (vl[l_idx] > vr[r_idx])
        {
            arr[idx++] = vr[r_idx++];
            total += (l_size - l_idx);
        }
        else
        {
            arr[idx++] = vl[l_idx++];
        }
    }
    while (l_idx < l_size)
    {
        arr[idx++] = vl[l_idx++];
    }
    while (r_idx < r_size)
    {
        arr[idx++] = vr[r_idx++];
    }
}

void merge_sort(vi &arr, const int &l, const int &r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);
    cout << total << '\n';
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}
