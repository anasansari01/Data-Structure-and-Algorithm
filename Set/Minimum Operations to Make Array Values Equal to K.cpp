class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    unordered_set<int> uS;

    for (auto num : nums)
    {
      if (num < k)
      {
        return -1;
      }
      if (num > k)
      {
        uS.insert(num);
      }
    }

    return uS.size();
  }
};
