class Solution
{
public:
  int countDays(int d, vector<vector<int>> &m)
  {
    int n = m.size(), sum = 0;
    sort(m.begin(), m.end(), [&](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int prev = 1;
    for (int i = 0; i < n; i++)
    {
      int strt = m[i][0];
      int end = m[i][1];

      if (prev < strt)
      {
        sum += (strt - prev);
      }

      prev = max(prev, end + 1);
    }

    if (prev <= d)
    {
      sum += (d - prev + 1);
    }

    return sum;
  }
};