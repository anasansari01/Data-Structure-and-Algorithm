class Solution
{
public:
  int mostProfitablePath(vector<vector<int>> &e, int b, vector<int> &a)
  {
    int n = a.size(), maxInc = INT_MIN;
    tree.resize(n);
    v.assign(n, false);

    queue<vector<int>> nQ;
    nQ.push({0, 0, 0});

    for (vector<int> edge : e)
    {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }

    bobPath(b, 0);

    v.assign(n, false);
    while (!nQ.empty())
    {

      int sN = nQ.front()[0], t = nQ.front()[1], inc = nQ.front()[2];

      if (bPath.find(sN) == bPath.end() || t < bPath[sN])
      {
        inc += a[sN];
      }
      else if (t == bPath[sN])
      {
        inc += (a[sN] / 2);
      }

      if (tree[sN].size() == 1 && sN != 0)
      {
        maxInc = max(maxInc, inc);
      }

      for (int adj : tree[sN])
      {
        if (!v[adj])
        {
          nQ.push({adj, t + 1, inc});
        }
      }

      v[sN] = true;
      nQ.pop();
    }

    return maxInc;
  }

private:
  unordered_map<int, int> bPath;
  vector<int> v;
  vector<vector<int>> tree;

  bool bobPath(int sN, int time)
  {
    bPath[sN] = time;
    v[sN] = true;

    if (sN == 0)
      return true;

    for (int nB : tree[sN])
    {
      if (!v[nB])
      {
        if (bobPath(nB, time + 1))
        {
          return true;
        }
      }
    }

    bPath.erase(sN);
    return false;
  }
};