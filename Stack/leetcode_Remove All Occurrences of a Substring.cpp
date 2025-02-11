class Solution
{
public:
  string removeOccurrences(string s, string part)
  {
    string res = "";
    int partLen = part.size();

    for (char c : s)
    {
      res.push_back(c);

      if (res.size() >= partLen && res.substr(res.size() - partLen) == part)
      {
        res.erase(res.size() - partLen);
      }
    }

    return res;
  }
};