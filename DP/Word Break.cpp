class Solution
{
public:
  bool wordBreak(string &s, vector<string> &d)
  {
    unordered_set<string> dict(d.begin(), d.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    int maxLen = 0;
    for (string &word : d)
    {
      maxLen = max(maxLen, (int)word.length());
    }

    for (int i = 1; i <= n; ++i)
    {
      for (int j = max(0, i - maxLen); j < i; ++j)
      {
        if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
        {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};