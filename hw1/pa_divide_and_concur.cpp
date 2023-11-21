#include <bits/stdc++.h>
using namespace std;
int max(const int &a, const int &b, const int &c)
{
    return max(a, max(b, c));
}

int maxCrossingSum(vector<int> &arr, int l, int m, int r)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        left_sum = max(sum, left_sum);
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= r; i++)
    {
        sum += arr[i];
        right_sum = max(sum, right_sum);
    }

    return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}

int maxSubArraySum(vector<int> &arr, int l, int r)
{
    if (l > r)
        return INT_MIN;
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    return max(maxSubArraySum(arr, l, m - 1),
               maxSubArraySum(arr, m + 1, r),
               maxCrossingSum(arr, l, m, r));
}

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << maxSubArraySum(arr, 0, n - 1);
    return 0;
}
