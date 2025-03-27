class Solution
{
public:
  // Function to find the minimum number of platforms required at the
  // railway station such that no train waits.
  int findPlatform(vector<int> &arr, vector<int> &dep)
  {
    int n = arr.size();
    vector<int> time(2361, 0);
    for (int i = 0; i < n; i++)
    {
      time[arr[i]] += 1;
      time[dep[i] + 1] -= 1;
    }

    int maxCnt = 0, cntsum = 0;
    for (int i = 0; i < 2361; i++)
    {
      cntsum += time[i];
      maxCnt = max(maxCnt, cntsum);
    }

    return maxCnt;
  }
};