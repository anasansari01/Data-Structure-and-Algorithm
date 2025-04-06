class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    if (nums.empty())
      return {};
    sort(nums.begin(), nums.end());
    int n = nums.size(), max_i = 0;
    vector<int> dp(n, 1), prev(n, -1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
          dp[i] = dp[j] + 1, prev[i] = j;
    for (int i = 1; i < n; ++i)
      if (dp[i] > dp[max_i])
        max_i = i;
    vector<int> res;
    while (max_i != -1)
      res.push_back(nums[max_i]), max_i = prev[max_i];
    reverse(res.begin(), res.end());
    return res;
  }
};