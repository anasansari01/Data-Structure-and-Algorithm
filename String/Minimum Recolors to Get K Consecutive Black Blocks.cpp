class Solution
{
public:
  int minimumRecolors(string b, int k)
  {
    int wCount = 0, minWhite = INT_MAX;

    for (int i = 0; i < k; i++)
    {
      if (b[i] == 'W')
        wCount++;
    }
    minWhite = wCount;

    for (int i = k; i < b.size(); i++)
    {
      if (b[i] == 'W')
        wCount++;
      if (b[i - k] == 'W')
        wCount--;
      minWhite = min(minWhite, wCount);
    }

    return minWhite;
  }
};
