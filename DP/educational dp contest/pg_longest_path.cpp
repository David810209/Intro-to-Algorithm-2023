#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
const int INF = INT_MAX;
const int N = 100005;

vvi adj(N);
vi order;
vi vis(N, 0);
vi dp(N, 0);
int n, m, u, v;

void dfs(int v)
{
    vis[v] = true;
    for (int &x : adj[v])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
    order.push_back(v);
}

void topological_sort()
{
    order.clear();
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(order));
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topological_sort();
    for (int &x : order)
    {
        for (int &i : adj[x])
        {
            dp[i] = max(dp[i], dp[x] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.begin() + n + 1) << '\n';
    return 0;
}
