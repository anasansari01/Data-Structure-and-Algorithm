class Solution
{
public:
  long long maximumTripletValue(vector<int> &num)
  {
    int n = num.size();
    vector<int> p(n), s(n);

    p[0] = num[0];
    for (int i = 1; i < n; i++)
    {
      p[i] = max(p[i - 1], num[i]);
    }

    s[n - 1] = num[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      s[i] = max(s[i + 1], num[i]);
    }

    long long maxVal = 0;
    for (int i = 1; i < n - 1; i++)
    {
      maxVal = max(maxVal, (long long)(p[i - 1] - num[i]) * s[i + 1]);
    }

    return maxVal;
  }
};