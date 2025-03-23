class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &road : roads)
    {
      int u = road[0], v = road[1], w = road[2];
      adj[u].emplace_back(w, v);
      adj[v].emplace_back(w, u);
    }

    int MOD = 1e9 + 7;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;
    min_heap.push({0, 0});

    vector<long long> min_cost(n, LLONG_MAX);
    vector<int> path_count(n, 0);
    min_cost[0] = 0;
    path_count[0] = 1;

    while (!min_heap.empty())
    {
      auto [cost, node] = min_heap.top();
      min_heap.pop();

      for (auto &[nei_cost, nei] : adj[node])
      {
        if (cost + nei_cost < min_cost[nei])
        {
          min_cost[nei] = cost + nei_cost;
          path_count[nei] = path_count[node];
          min_heap.push({cost + nei_cost, nei});
        }
        else if (cost + nei_cost == min_cost[nei])
        {
          path_count[nei] = (path_count[nei] + path_count[node]) % MOD;
        }
      }
    }

    return path_count[n - 1];
  }
};