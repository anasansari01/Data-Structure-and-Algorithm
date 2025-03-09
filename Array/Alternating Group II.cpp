class Solution
{
public:
  int numberOfAlternatingGroups(vector<int> &c, int k)
  {
    int n = c.size();
    if (k == 1)
      return n;

    vector<bool> isAlternating(n);
    for (int i = 0; i < n; i++)
    {
      isAlternating[i] = (c[i] != c[(i + 1) % n]);
    }

    int count = 0;
    int validPairs = 0;

    for (int i = 0; i < k - 1; i++)
    {
      if (isAlternating[i])
        validPairs++;
    }

    if (validPairs == k - 1)
      count++;

    for (int i = 1; i < n; i++)
    {
      if (isAlternating[(i - 1 + n) % n])
        validPairs--;
      if (isAlternating[(i + k - 2) % n])
        validPairs++;
      if (validPairs == k - 1)
        count++;
    }

    return count;
  }
};