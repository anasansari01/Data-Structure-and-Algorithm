class Solution
{
public:
  int findMaxSum(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return arr[0];

    int fst = arr[0], snd = 0;

    for (int i = 1; i < n; i++)
    {
      int l = max(fst, arr[i] + snd);
      snd = fst;
      fst = l;
    }

    return fst;
  }
};