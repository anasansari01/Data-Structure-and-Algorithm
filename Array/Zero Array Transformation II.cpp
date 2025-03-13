class Solution
{
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    int m = queries.size();
    int l = 0, r = m + 1;

    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (check(nums, queries, mid, n))
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }
    return l > m ? -1 : l;
  }

private:
  bool check(vector<int> &nums, vector<vector<int>> &queries, int k, int n)
  {
    vector<int> d(n + 1, 0);
    for (int i = 0; i < k; ++i)
    {
      int l = queries[i][0], r = queries[i][1], val = queries[i][2];
      d[l] += val;
      d[r + 1] -= val;
    }

    int s = 0;
    for (int i = 0; i < n; ++i)
    {
      s += d[i];
      if (nums[i] > s)
      {
        return false;
      }
    }
    return true;
  }
};
