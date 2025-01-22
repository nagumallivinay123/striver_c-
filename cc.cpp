#define ll long long
ll fin = 0;
void dfs(int v, vector<ll> &d, vector<ll> &w, vector<vector<array<int, 2>>> &adj, int p = -1)
{
    int n = int(d.size());
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        ll val = d[n - 1] - d[mid];
        if (val <= w[v])
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (ans != -1)
    {
        fin += n - 1 - ans;
    }
    for (auto x : adj[v])
    {
        if (x[0] == p)
            continue;
        d.push_back(d.back() + x[1]);
        dfs(x[0], d, w, adj, v);
        d.pop_back();
    }
}
int countCompatiblePairs(int n, vector<int> from, vector<int> to, vector<int> weight, vector<int> value)
{
    vector<vector<array<int, 2>>> adj(n);
    vector<int> a = from, b = to;
    int m = a.size();
    vector<int> w = weight;
    for (int i = 0; i < m; i++)
    {
        --a[i];
        --b[i];
        adj[a[i]].push_back({b[i], w[i]});
        adj[b[i]].push_back({a[i], w[i]});
    }
    fin = 0;
    vector<ll> v = value;
    vector<ll> d;
    d.push_back(0);
    dfs(0, d, v, adj);
    return fin;
}