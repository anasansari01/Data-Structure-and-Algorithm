class Solution
{
public:
  int lis(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    vector<int> maxi(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (arr[j] < arr[i])
          maxi[i] = max(maxi[i], maxi[j] + 1);
      }
      ans = max(ans, maxi[i]);
    }

    return ans;
  }
};