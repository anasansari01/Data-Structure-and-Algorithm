class Solution
{
public:
  vector<int> constructDistancedSequence(int n)
  {
    int size = 2 * n - 1;
    vector<int> res(size, 0);
    vector<bool> used(n + 1, false);
    backtrack(res, used, n, 0, size);
    return res;
  }

private:
  bool backtrack(vector<int> &res, vector<bool> &used, int n, int index, int size)
  {
    if (index == size)
      return true;
    if (res[index] != 0)
      return backtrack(res, used, n, index + 1, size);

    for (int num = n; num >= 1; --num)
    {
      if (used[num])
        continue;

      if (num == 1)
      {
        res[index] = 1;
        used[1] = true;
        if (backtrack(res, used, n, index + 1, size))
          return true;
        res[index] = 0;
        used[1] = false;
      }
      else
      {
        int j = index + num;
        if (j < size && res[j] == 0)
        {
          res[index] = res[j] = num;
          used[num] = true;
          if (backtrack(res, used, n, index + 1, size))
            return true;
          res[index] = res[j] = 0;
          used[num] = false;
        }
      }
    }
    return false;
  }
};