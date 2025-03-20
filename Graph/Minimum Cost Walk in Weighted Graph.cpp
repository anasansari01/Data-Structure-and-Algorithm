class Solution
{
public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
  {
    vector<int> parent(n);
    vector<int> rank(n, 1);
    vector<int> min_and(n, 0x7FFFFFFF);
    for (int i = 0; i < n; ++i)
      parent[i] = i;

    auto find = [&](int u)
    {
      while (parent[u] != u)
      {
        parent[u] = parent[parent[u]];
        u = parent[u];
      }
      return u;
    };

    auto union_sets = [&](int u, int v, int w)
    {
      int pu = find(u), pv = find(v);
      if (pu != pv)
      {
        if (rank[pu] > rank[pv])
        {
          parent[pv] = pu;
          min_and[pu] &= min_and[pv] & w;
        }
        else if (rank[pu] < rank[pv])
        {
          parent[pu] = pv;
          min_and[pv] &= min_and[pu] & w;
        }
        else
        {
          parent[pv] = pu;
          min_and[pu] &= min_and[pv] & w;
          rank[pu]++;
        }
      }
      else
      {
        min_and[pu] &= w;
      }
    };

    for (const auto &e : edges)
    {
      int u = e[0], v = e[1], w = e[2];
      union_sets(u, v, w);
    }

    vector<int> ans;
    for (const auto &q : queries)
    {
      int s = q[0], t = q[1];
      int ps = find(s), pt = find(t);
      if (ps != pt)
      {
        ans.push_back(-1);
      }
      else
      {
        ans.push_back(min_and[ps]);
      }
    }

    return ans;
  }
};