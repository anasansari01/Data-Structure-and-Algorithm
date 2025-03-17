class Solution
{
public:
  bool isSubsetSum(vector<int> &arr, int sum)
  {
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 0; i < arr.size(); i++)
    {

      for (int j = sum; j >= arr[i]; j--)
      {

        if (dp[j - arr[i]])
          dp[j] = true;
      }
    }

    return dp[sum];
  }
};