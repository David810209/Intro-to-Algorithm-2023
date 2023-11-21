#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, q;
    cin >> q >> k;

    priority_queue<int> max_heap; // Using max-heap to get kth largest
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < q; i++)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int xi;
            cin >> xi;
            max_heap.push(xi);
            if (max_heap.size() > k)
            {
                min_heap.push(max_heap.top()); // Remove the largest element to keep k elements
                max_heap.pop();
            }
        }
        else if (query_type == 2)
        {
            if (max_heap.size() == k)
            {
                cout << max_heap.top() << '\n';
                max_heap.pop();
                if (!min_heap.empty())
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
/*
15 2
2
1 5
2
1 7
2
1 3
1 1
2
1 9
1 12
2
2
2
2
2


*/
