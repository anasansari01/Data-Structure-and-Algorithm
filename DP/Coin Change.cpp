class Solution
{
public:
  int count(vector<int> &coins, int sum)
  {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (auto coin : coins)
    {
      for (int subSum = coin; subSum < sum + 1; subSum++)
      {
        dp[subSum] += dp[subSum - coin];
      }
    }

    return dp[sum];
  }
};