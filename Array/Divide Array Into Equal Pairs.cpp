class Solution
{
public:
  bool divideArray(vector<int> &nums)
  {
    int n = nums.size();
    n = n / 2;
    bool flag = true;
    unordered_map<int, int> uMp;

    for (auto num : nums)
      uMp[num]++;

    for (int i = 1; i <= 500; i++)
    {

      if (uMp.find(i) != uMp.end())
      {

        if (uMp[i] % 2 != 0)
          flag = false;
      }
    }

    return flag;
  }
};