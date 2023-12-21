#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

const int N = 200005;
vi low(N), disc(N, 0), instack(N, 0), component(N);
stack<int> st;
int t = 0;
vvi adj(N);

void tarjan(int i)
{
    disc[i] = low[i] = ++t;
    st.push(i);
    instack[i] = 1;
    for (auto &j : adj[i])
    {
        if (!disc[j])
        {
            tarjan(j);
            low[i] = min(low[i], low[j]);
        }
        else if (instack[j])
        {
            low[i] = min(low[i], disc[j]);
        }
    }
    if (disc[i] == low[i])
    {
        int j;
        do
        {
            j = st.top();
            st.pop();
            instack[j] = 0;
            component[j] = i;
        } while (j != i);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            tarjan(i);
        }
    }

    vi tmp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        tmp[component[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i] == 1)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
