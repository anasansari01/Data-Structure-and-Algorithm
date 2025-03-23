class Solution
{
public:
  int countWays(string &d)
  {
    int n = d.length();
    if (n == 0 || d[0] == '0')
    {
      return 0;
    }

    int prev1 = 1, prev2 = 1;
    for (int i = 1; i < n; i++)
    {
      int curr = 0;
      if (d[i] != '0')
      {
        curr += prev1;
      }
      string prev = d.substr(i - 1, 2);
      if (checkS(prev))
      {
        curr += prev2;
      }
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }

private:
  bool checkS(string &s)
  {
    return s >= "10" && s <= "26";
  }
};