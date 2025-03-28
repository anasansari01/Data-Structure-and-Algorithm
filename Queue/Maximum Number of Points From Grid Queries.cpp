class Solution
{
public:
  vector<int> maxPoints(vector<vector<int>> &g, vector<int> &q)
  {
    int n = g.size(), m = g[0].size(), k = q.size();

    vector<int> ans(k, 0);
    vector<pair<int, int>> qIdx(k);

    for (int i = 0; i < k; i++)
    {
      qIdx[i] = {q[i], i};
    }

    sort(qIdx.begin(), qIdx.end());

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({g[0][0], {0, 0}});

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[0][0] = true;

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int pts = 0;

    for (auto &[val, idx] : qIdx)
    {
      while (!pq.empty() && pq.top().first < val)
      {
        auto [v, p] = pq.top();
        pq.pop();

        int x = p.first, y = p.second;
        pts++;

        for (auto &d : dir)
        {
          int nx = x + d.first;
          int ny = y + d.second;

          if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
          {
            vis[nx][ny] = true;
            pq.push({g[nx][ny], {nx, ny}});
          }
        }
      }
      ans[idx] = pts;
    }

    return ans;
  }
};
