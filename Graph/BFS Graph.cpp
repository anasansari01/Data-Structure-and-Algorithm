
class Solution
{
public:
  vector<int> bfs(vector<vector<int>> &adj)
  {
    vector<int> ans;
    int n = adj.size();
    vector<int> v(n, 0);

    queue<int> q;
    q.push(0);
    v[0] = 1;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      ans.push_back(node);

      for (int neig : adj[node])
      {
        if (!v[neig])
        {
          v[neig] = 1;
          q.push(neig);
        }
      }
    }

    return ans;
  }
};