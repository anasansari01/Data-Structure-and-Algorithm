class Solution
{
public:
  int minCost(vector<vector<int>> &h)
  {
    int n = h.size(), res = 0;
    vector<int> minD(n, INT_MAX);
    vector<bool> vis(n, false);
    minD[0] = 0;

    for (int i = 0; i < n; ++i)
    {
      int u = -1;
      for (int j = 0; j < n; ++j)
        if (!vis[j] && (u == -1 || minD[j] < minD[u]))
          u = j;

      vis[u] = true;
      res += minD[u];

      for (int v = 0; v < n; ++v)
      {
        if (!vis[v])
        {
          int d = abs(h[u][0] - h[v][0]) + abs(h[u][1] - h[v][1]);
          if (d < minD[v])
            minD[v] = d;
        }
      }
    }

    return res;
  }
};