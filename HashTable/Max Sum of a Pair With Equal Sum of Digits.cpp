class Solution
{
public:
  int maximumSum(vector<int> &nums)
  {
    int maxSum = -1;
    unordered_map<int, int> mp;

    for (auto num : nums)
    {
      int digitSum = 0;
      int number = num;

      while (number != 0)
      {

        digitSum += number % 10;
        number /= 10;
      }

      if (mp.find(digitSum) != mp.end())
        maxSum = max(maxSum, num + mp[digitSum]);

      mp[digitSum] = max(num, mp[digitSum]);
    }

    return maxSum;
  }
};