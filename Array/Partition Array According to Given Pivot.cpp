class Solution
{
public:
  vector<int> pivotArray(vector<int> &nums, int pivot)
  {
    vector<int> l, r, e, res;
    for (auto num : nums)
    {
      if (num == pivot)
      {
        e.push_back(num);
      }
      else if (num < pivot)
      {
        l.push_back(num);
      }
      else
      {
        r.push_back(num);
      }
    }

    for (auto num : l)
    {
      res.push_back(num);
    }
    for (auto num : e)
    {
      res.push_back(num);
    }
    for (auto num : r)
    {
      res.push_back(num);
    }

    return res;
  }
};