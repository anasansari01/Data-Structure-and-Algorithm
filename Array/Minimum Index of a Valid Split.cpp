class Solution
{
public:
  int minimumIndex(const vector<int> &nums)
  {
    // get the dominant element
    int current = 0;
    int freq = 1;
    int sz = nums.size();
    for (int num : nums)
    {
      if (num == current)
      {
        freq++;
      }
      else
      {
        freq--;
        if (freq == 0)
        {
          current = num;
          freq = 1;
        }
      }
    }
    // count the often the dominant element occurs
    int total = 0;
    for (int num : nums)
    {
      if (num == current)
      {
        total++;
      }
    }
    // check each splitting point
    freq = 0;
    for (int i = 0; i < sz; i++)
    {
      if (nums[i] == current)
      {
        freq++;
      }
      if (2 * freq > i + 1 && 2 * (total - freq) > sz - i - 1)
      {
        return i;
      }
    }
    return -1;
  }
};