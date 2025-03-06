class Solution
{
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    vector<int> res(2, 0);
    unordered_map<int, int> uMp;
    set<int> s;
    int rpt = 0, sum = 0;

    for (auto &val : grid)
    {
      for (auto num : val)
      {
        uMp[num]++;
        if (uMp[num] == 2)
        {
          rpt = num;
        }
        sum += num;
      }
    }

    int n = grid.size();
    n = n * n;

    int actSum = (n * (n + 1)) / 2;
    int miss = actSum - (sum - rpt);

    res[0] = rpt;
    res[1] = miss;

    return res;
  }
};