class Solution
{
private:
  bool vowel(char c)
  {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  long long f(const string &word, int k)
  {
    long long ans = 0;
    int l = 0, x = 0;
    unordered_map<char, int> cnt;

    for (char c : word)
    {
      if (vowel(c))
      {
        cnt[c]++;
      }
      else
      {
        ++x;
      }

      while (x >= k && cnt.size() == 5)
      {
        char d = word[l++];
        if (vowel(d))
        {
          if (--cnt[d] == 0)
          {
            cnt.erase(d);
          }
        }
        else
        {
          --x;
        }
      }
      ans += l;
    }
    return ans;
  }

public:
  long long countOfSubstrings(string word, int k)
  {
    return f(word, k) - f(word, k + 1);
  }
};
