class Solution
{
public:
  int numTilePossibilities(string tiles)
  {
    int letterCount[26] = {0};
    for (char c : tiles)
    {
      ++letterCount[c - 'A'];
    }
    return dfs(letterCount);
  }

private:
  int dfs(int *count)
  {
    int result = 0;
    for (int i = 0; i < 26; ++i)
    {
      if (count[i] > 0)
      {
        ++result;
        --count[i];
        result += dfs(count);
        ++count[i];
      }
    }
    return result;
  }
};