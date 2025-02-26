// Solved using kadane algorithm:

class Solution
{
public:
  int maxAbsoluteSum(vector<int> &nums)
  {

    int maxSum = maxKadane(nums);
    int minSum = minKadane(nums);

    return max(abs(maxSum), abs(minSum));
  }

private:
  int maxKadane(vector<int> &nums)
  {
    int n = nums.size(), maxSum = INT_MIN, maxEnd = 0;

    for (int i = 0; i < n; i++)
    {
      maxEnd = maxEnd + nums[i];
      if (maxSum < maxEnd)
      {
        maxSum = maxEnd;
      }
      if (maxEnd < 0)
      {
        maxEnd = 0;
      }
    }

    return maxSum;
  }
  int minKadane(vector<int> &nums)
  {
    int n = nums.size(), minSum = INT_MAX, minEnd = 0;

    for (int i = 0; i < n; i++)
    {
      minEnd = minEnd + nums[i];
      if (minSum > minEnd)
      {
        minSum = minEnd;
      }
      if (minEnd > 0)
      {
        minEnd = 0;
      }
    }

    return minSum;
  }
};