#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll total = 0;

void merge(vector<int> &arr, int l, int m, int r)
{

    int l_size = m - l + 1;
    int r_size = r - m;
    vector<int> arr_l(l_size);
    vector<int> arr_r(r_size);
    ll l_sum = 0;
    for (int i = 0; i < l_size; i++)
    {
        arr_l[i] = arr[l + i];
        l_sum += arr_l[i];
    }

    for (int i = 0; i < r_size; i++)
    {
        arr_r[i] = arr[m + i + 1];
    }

    int index = l, l_index = 0, r_index = 0;

    while (l_index < l_size && r_index < r_size)
    {
        if (arr_l[l_index] <= arr_r[r_index])
        {
            arr[index] = arr_r[r_index];
            total = total - l_sum + (ll)(l_size - l_index) * arr_r[r_index];
            index++;
            r_index++;
        }
        else
        {
            arr[index] = arr_l[l_index];
            l_sum -= arr_l[l_index];
            index++;
            l_index++;
        }
    }
    while (l_index < l_size)
    {
        arr[index] = arr_l[l_index];
        index++;
        l_index++;
    }
    while (r_index < r_size)
    {
        arr[index] = arr_r[r_index];
        index++;
        r_index++;
    }
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);
    cout << total << '\n';
    return 0;
}
