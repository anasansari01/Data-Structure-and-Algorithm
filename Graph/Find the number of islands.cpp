class Solution
{
public:
  void dfs(vector<vector<char>> &g, int x, int y, int n, int m)
  {
    if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] != 'L')
      return;
    g[x][y] = 'W';

    vector<pair<int, int>> dir = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    for (int i = 0; i < dir.size(); ++i)
    {
      int dx = dir[i].first;
      int dy = dir[i].second;
      dfs(g, x + dx, y + dy, n, m);
    }
  }

  int countIslands(vector<vector<char>> &g)
  {
    int n = g.size(), m = g[0].size(), count = 0;

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (g[i][j] == 'L')
        {
          count++;
          dfs(g, i, j, n, m);
        }
      }
    }

    return count;
  }
};