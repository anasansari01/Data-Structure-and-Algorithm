class Solution
{
public:
  int knapsack(int W, vector<int> &val, vector<int> &wt)
  {
    int n = val.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = W; j >= wt[i]; j--)
      {
        dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
      }
    }

    return dp[W];
  }
};