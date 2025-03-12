class Solution
{
public:
  int maximumCount(vector<int> &nums)
  {
    int neg = 0, zero = 0;

    for (auto num : nums)
    {
      if (num == 0)
      {
        zero++;
      }
      else if (num < 0)
      {
        neg++;
      }
      else
      {
        break;
      }
    }
    int pos = nums.size() - (neg + zero);

    return (pos > neg) ? pos : neg;
  }
};