class Solution
{
public:
  void dfs(int u, vector<int> adj[], vector<bool> &vis, vector<int> &d,
           vector<int> &l, vector<int> &par, vector<bool> &ap, int &t)
  {

    vis[u] = true;
    d[u] = l[u] = ++t;
    int ch = 0;

    for (int v : adj[u])
    {
      if (!vis[v])
      {
        par[v] = u;
        ch++;
        dfs(v, adj, vis, d, l, par, ap, t);
        l[u] = min(l[u], l[v]);
        if (par[u] == -1 && ch > 1)
          ap[u] = true;
        if (par[u] != -1 && l[v] >= d[u])
          ap[u] = true;
      }
      else if (v != par[u])
      {
        l[u] = min(l[u], d[v]);
      }
    }
  }

  vector<int> articulationPoints(int V, vector<vector<int>> &e)
  {
    vector<int> adj[V];
    for (auto &x : e)
    {
      int u = x[0], v = x[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> vis(V, 0), ap(V, 0);
    vector<int> d(V, -1), l(V, -1), par(V, -1);
    int t = 0;

    for (int i = 0; i < V; ++i)
      if (!vis[i])
        dfs(i, adj, vis, d, l, par, ap, t);

    vector<int> res;
    for (int i = 0; i < V; ++i)
      if (ap[i])
        res.push_back(i);

    return res.empty() ? vector<int>{-1} : res;
  }
};
