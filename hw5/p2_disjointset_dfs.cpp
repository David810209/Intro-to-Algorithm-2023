#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = 200005;
vi p(N);
vi color(N);
vi set_size(N, 1); // array to store the size of each set
vi black_cnt(N, 0);
int n;

vvi adj(N);

void init()
{
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }
}

int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y)
    {
        if (set_size[x] < set_size[y])
            swap(x, y);

        p[y] = x;
        set_size[x] += set_size[y];
        set_size[y] = 0;
        black_cnt[x] += black_cnt[y];
    }
}

int dfs(int u)
{
    if (color[u])
        return 0;
    queue<int> q;
    vi vis(N, 0);
    q.push(u);
    vis[u] = 1;
    int dis = 0;
    while (!q.empty())
    {
        int lSize = q.size();
        dis++;
        while (lSize-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int &x : adj[cur])
            {
                if (!vis[x])
                {
                    if (color[x])
                        return dis;
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> n >> q;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        if (color[i])
        {
            black_cnt[i]++;
        }
    }
    while (q--)
    {
        int op;
        cin >> op;
        int u, v;
        if (op == 1)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            merge(u, v);
        }
        else if (op == 2)
        {
            cin >> u;
            cout << black_cnt[find(u)] << '\n';
        }
        else if (op == 3)
        {
            cin >> u;
            cout << dfs(u) << '\n';
        }
    }

    return 0;
}
