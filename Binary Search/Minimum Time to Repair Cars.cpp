class Solution
{
public:
  long long repairCars(vector<int> &rk, int c)
  {
    long long l = 1, r = (long long)*min_element(rk.begin(), rk.end()) * (long long)c * c;
    long long res = r;

    while (l <= r)
    {
      long long m = l + (r - l) / 2;
      if (canRepair(rk, c, m))
      {
        res = m;
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
  bool canRepair(vector<int> &r, int c, long long m)
  {
    long long count = 0;
    for (int rate : r)
    {
      count += (long long)sqrt(m / rate);
      if (count >= c)
        return true;
    }
    return count >= c;
  }
};
