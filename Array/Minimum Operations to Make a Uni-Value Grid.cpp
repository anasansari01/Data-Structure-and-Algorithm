class Solution
{
public:
  int minOperations(vector<vector<int>> &grid, int x)
  {
    vector<int> nums;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        nums.push_back(grid[i][j]);
      }
    }

    int rem = nums[0] % x;
    for (int i = 1; i < nums.size(); ++i)
    {
      if (nums[i] % x != rem)
      {
        return -1;
      }
    }

    sort(nums.begin(), nums.end());

    int med = nums[nums.size() / 2], ops = 0;
    for (int num : nums)
    {
      ops += abs(num - med) / x;
    }

    return ops;
  }
};
