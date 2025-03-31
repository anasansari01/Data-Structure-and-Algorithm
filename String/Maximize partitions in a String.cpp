class Solution
{
public:
  int maxPartitions(string &s)
  {
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
      mp[s[i]] = i;

    int limit = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      limit = max(limit, mp[s[i]]);
      if (limit == i)
      {
        cnt++;
        limit = i + 1;
      }
    }
    return cnt;
  }
};