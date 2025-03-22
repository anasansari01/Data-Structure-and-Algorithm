class Solution
{
public:
  unordered_map<int, vector<int>> adj;
  unordered_set<int> vis;

  int countCompleteComponents(int n, vector<vector<int>> &e)
  {
    for (auto &ed : e)
    {
      adj[ed[0]].push_back(ed[1]);
      adj[ed[1]].push_back(ed[0]);
    }

    int res = 0;
    for (int v = 0; v < n; ++v)
    {
      if (vis.count(v))
        continue;
      vector<int> comp;
      dfs(v, comp);
      bool compFlag = true;
      for (int v2 : comp)
      {
        if (adj[v2].size() != comp.size() - 1)
        {
          compFlag = false;
          break;
        }
      }
      if (compFlag)
        res++;
    }
    return res;
  }

private:
  void dfs(int v, vector<int> &comp)
  {
    if (vis.count(v))
      return;
    vis.insert(v);
    comp.push_back(v);
    for (int nei : adj[v])
      dfs(nei, comp);
  }
};