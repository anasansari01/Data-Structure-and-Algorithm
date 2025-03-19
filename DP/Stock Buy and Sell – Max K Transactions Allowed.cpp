class Solution
{
public:
  int n, dp[1001][201][2];

  int mp(int i, int k, bool b, vector<int> &p)
  {
    if (k == 0 || i >= n)
      return 0;

    if (dp[i][k][b] != -1)
      return dp[i][k][b];

    int res = 0;

    if (b)
    {
      int buy = mp(i + 1, k, false, p) - p[i];
      int skip = mp(i + 1, k, true, p);
      res = max(buy, skip);
    }
    else
    {
      int sell = p[i] + mp(i + 1, k - 1, true, p);
      int skip = mp(i + 1, k, false, p);
      res = max(sell, skip);
    }

    return dp[i][k][b] = res;
  }

  int maxProfit(vector<int> &p, int k)
  {
    n = p.size();
    memset(dp, -1, sizeof(dp));
    return mp(0, k, true, p);
  }
};
