class Solution
{
public:
  int total = 0;

  void dfs(vector<int> &nums, int index, int xorSum)
  {
    if (index == nums.size())
    {
      total += xorSum;
      return;
    }
    dfs(nums, index + 1, xorSum);
    dfs(nums, index + 1, xorSum ^ nums[index]);
  }

  int subsetXORSum(vector<int> &nums)
  {
    total = 0;
    dfs(nums, 0, 0);
    return total;
  }
};
