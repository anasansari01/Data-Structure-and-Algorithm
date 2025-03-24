class Solution
{
public:
  int matrixMultiplication(vector<int> &arr)
  {
    int n = arr.size();
    if (n <= 1)
      return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int length = 2; length < n; length++)
    {
      for (int i = 1; i < n - length + 1; i++)
      {
        int j = i + length - 1;
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++)
        {
          int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
          if (cost < dp[i][j])
          {
            dp[i][j] = cost;
          }
        }
      }
    }

    return dp[1][n - 1];
  }
};