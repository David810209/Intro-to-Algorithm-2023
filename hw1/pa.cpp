#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, left = 0, curleft = 0, right = 0, curright = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long int maxsum = arr[0], cursum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (cursum + arr[i] < arr[i])
        {
            cursum = arr[i];
            curleft = i;
            curright = i;
        }
        else
        {
            cursum += arr[i];
            curright = i;
        }
        if (cursum > maxsum)
        {
            maxsum = cursum;
            left = curleft;
            right = curright;
        }
    }
    cout << maxsum << '\n'
         << left + 1 << ' ' << right + 1 << '\n';

    return 0;
}

/*
    long long int* prefix = new long long int[n+1];
    prefix[0] = 0;
    for(int i = 1;i <= n;i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    long long int result = INT_MIN;
    int minSubarr = INT_MAX;
    for(int i = 0;i <= n;i++){
        if(prefix[i]<minSubarr){
            minSubarr = prefix[i];
            leftIndex = i;
        }

        if(prefix[i]-minSubarr >result){
            result = prefix[i]-minSubarr;
            left = leftIndex;
            right = i;
        }
    }*/
