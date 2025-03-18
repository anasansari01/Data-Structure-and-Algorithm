class Solution
{
public:
  bool equalPartition(vector<int> &arr)
  {
    int n = arr.size(), totalSum = 0;
    for (int num : arr)
    {
      totalSum += num;
    }
    if (totalSum % 2 != 0)
    {
      return false;
    }

    int target = totalSum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++)
    {
      dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= target; j++)
      {
        if (arr[i - 1] <= j)
        {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][target];
  }
};
