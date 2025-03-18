class Solution
{
public:
  int longestNiceSubarray(vector<int> &nums)
  {
    int n = nums.size();
    int start = 0, bitMask = 0, maxLength = 0;

    for (int end = 0; end < n; ++end)
    {
      while ((bitMask & nums[end]) != 0)
      {
        bitMask ^= nums[start];
        start++;
      }

      bitMask |= nums[end];

      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};