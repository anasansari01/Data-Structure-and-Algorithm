class Solution
{
public:
  int lenLongestFibSubseq(vector<int> &arr)
  {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> uMp;
    for (int i = 0; i < n; i++)
    {
      uMp[arr[i]] = i;
    }
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {

        int diff = arr[i] - arr[j];

        if (uMp.find(diff) != uMp.end() && uMp[diff] < j)
        {
          int k = uMp[diff];
          dp[i][j] = dp[j][k] + 1;

          maxLen = max(maxLen, dp[i][j]);
        }
      }
    }

    return maxLen >= 3 ? maxLen : 0;
  }
};