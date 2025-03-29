class Solution
{
public:
  vector<int> jobSequencing(vector<int> &d, vector<int> &p)
  {
    vector<pair<int, int>> vp;
    int n = d.size(), jbs = 0, mxP = 0;

    for (int i = 0; i < n; i++)
      vp.push_back({d[i], p[i]});

    sort(vp.begin(), vp.end());
    priority_queue<int> pq;

    int idx = n - 1, mxD = vp[n - 1].first;

    for (int i = mxD; i >= 1; i--)
    {
      while (idx >= 0 && vp[idx].first == i)
      {
        pq.push(vp[idx].second);
        idx--;
      }
      if (!pq.empty())
      {
        jbs++;
        mxP += pq.top();
        pq.pop();
      }
    }

    return {jbs, mxP};
  }
};