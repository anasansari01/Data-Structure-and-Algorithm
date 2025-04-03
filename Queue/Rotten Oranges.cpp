class Solution
{
public:
  int orangesRotting(vector<vector<int>> &mat)
  {
    int time = 0, n = mat.size(), m = mat[0].size(), zC = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (mat[i][j] == 2)
          q.push({i, j});
        else if (mat[i][j] == 1)
          zC++;

    if (zC == 0)
      return 0;

    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty())
    {
      int size = q.size();
      bool rott = false;

      for (int i = 0; i < size; i++)
      {
        auto idx = q.front();
        q.pop();
        int x = idx.first, y = idx.second;

        for (auto dr : direction)
        {
          int nX = x + dr.first;
          int nY = y + dr.second;

          if (nX >= 0 && nX < n && nY >= 0 && nY < m && mat[nX][nY] == 1)
          {
            mat[nX][nY] = 2;
            q.push({nX, nY});
            zC--;
            rott = true;
          }
        }
      }

      if (rott)
        time++;
    }

    return (zC) ? -1 : time;
  }
};