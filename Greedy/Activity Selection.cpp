class Solution
{
public:
  int activitySelection(vector<int> &s, vector<int> &f)
  {
    int cnt = 1, n = s.size();
    vector<pair<int, int>> mp;

    for (int i = 0; i < n; i++)
    {
      mp.push_back({s[i], f[i]});
    }

    sort(mp.begin(), mp.end(), [&](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    int fnsh = mp[0].second;
    for (int i = 1; i < n; i++)
    {

      if (fnsh < mp[i].first)
      {
        cnt++;
        fnsh = mp[i].second;
      }
    }

    return cnt;
  }
};