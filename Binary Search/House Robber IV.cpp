class Solution
{
public:
  int minCapability(vector<int> &nums, int k)
  {
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());
    int res = INT_MAX;

    while (l <= r)
    {
      int m = l + (r - l) / 2;
      if (check(nums, m, k))
      {
        res = min(res, m);
        r = m - 1;
      }
      else
      {
        l = m + 1;
      }
    }

    return res;
  }

private:
  bool check(vector<int> &nums, int m, int k)
  {
    int count = 0, i = 0;

    while (i < nums.size())
    {
      if (nums[i] <= m)
      {
        count++;
        i++;
      }
      i++;
    }

    return count >= k;
  }
};