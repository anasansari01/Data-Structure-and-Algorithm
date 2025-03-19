class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int res = 0, n = nums.size();

    for (int i = 0; i <= n - 3; i++)
    {
      if (nums[i] == 0)
      {
        res++;
        for (int j = 0; j < 3; j++)
        {
          nums[i + j] ^= 1;
        }
      }
    }

    for (int i = n - 2; i < n; i++)
      if (nums[i] == 0)
        return -1;

    return res;
  }
};