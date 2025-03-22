class Solution
{
public:
  int maxValue(vector<int> &arr)
  {
    int n = arr.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return arr[0];

    int rob1 = maxR(arr, 0, n - 2);
    int rob2 = maxR(arr, 1, n - 1);

    return max(rob1, rob2);
  }

private:
  int maxR(vector<int> &arr, int s, int e)
  {
    int p1 = 0, p2 = 0;

    for (int i = s; i <= e; i++)
    {
      int l = max(p1, arr[i] + p2);
      p2 = p1;
      p1 = l;
    }

    return p1;
  }
};