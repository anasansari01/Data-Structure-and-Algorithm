class Solution
{
public:
  int maximumCandies(vector<int> &c, long long k)
  {
    int r = *max_element(c.begin(), c.end());
    int l = 1, res = 0;

    while (l <= r)
    {
      int m = l + (r - l) / 2;
      if (check(c, k, m))
      {
        res = m;
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    return res;
  }

private:
  bool check(vector<int> &c, long long k, int m)
  {
    long long countK = 0;

    for (int i = 0; i < c.size(); i++)
    {
      countK += c[i] / m;
    }

    return countK >= k;
  }
};