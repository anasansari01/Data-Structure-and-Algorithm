class Solution
{
public:
  string longestPalindrome(string &S)
  {
    int start = 0, end = 0;
    int low, high;
    for (int i = 0; i < S.length(); i++)
    {
      low = i - 1;
      high = i;
      while (low >= 0 && high < S.length() && S[low] == S[high])
      {

        if (high - low + 1 > end)
        {
          end = high - low + 1;
          start = low;
        }
        low--;
        high++;
      }
      low = i - 1;
      high = i + 1;
      while (low >= 0 && high < S.length() && S[low] == S[high])
      {

        if (high - low + 1 > end)
        {
          end = high - low + 1;
          start = low;
        }
        low--;
        high++;
      }
    }
    if (end == 0)
      return S.substr(start, 1);
    return S.substr(start, end);
  }
};