class Solution
{
public:
  int numOfSubarrays(vector<int> &arr)
  {
    int n = arr.size();
    const int MOD = 1e9 + 7;

    int odd = 0, even = 1;
    int sum = 0, ans = 0;

    for (int num : arr)
    {
      sum = (sum + num) % 2;

      if (sum == 0)
      {
        ans = (ans + odd) % MOD;
        even++;
      }
      else
      {
        ans = (ans + even) % MOD;
        odd++;
      }
    }

    return ans;
  }
};
