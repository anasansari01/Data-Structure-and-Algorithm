class Solution
{
public:
  void dfs(int n, vector<int> adj[], vector<int> &vis, vector<int> &ans)
  {
    vis[n] = 1;
    for (int i = 0; i < adj[n].size(); ++i)
    {
      int ng = adj[n][i];
      if (!vis[ng])
        dfs(ng, adj, vis, ans);
    }
    ans.push_back(n);
  }

  vector<int> topoSort(int V, vector<vector<int>> &e)
  {
    vector<int> adj[V], vis(V, 0), ans;

    for (int i = 0; i < e.size(); ++i)
    {
      int u = e[i][0], v = e[i][1];
      adj[u].push_back(v);
    }

    for (int i = 0; i < V; ++i)
      if (!vis[i])
        dfs(i, adj, vis, ans);

    reverse(ans.begin(), ans.end());
    return ans;
  }
};