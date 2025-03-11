class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    vector<int> count(3, 0);
    int l = 0, res = 0;
    int n = s.length();

    for (int r = 0; r < n; r++)
    {
      count[s[r] - 'a']++;

      while (count[0] > 0 && count[1] > 0 && count[2] > 0)
      {
        res += (n - r);
        count[s[l] - 'a']--;
        l++;
      }
    }
    return res;
  }
};

// abca | abcab | abcabc
// bca    cab     abc