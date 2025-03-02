class Solution
{
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &n1, vector<vector<int>> &n2)
  {
    vector<vector<int>> ans;
    int n = n1.size(), m = n2.size();

    int i = 0, j = 0;

    while (i < n && j < m)
    {

      if (n1[i][0] == n2[j][0])
      {
        ans.push_back({n1[i][0], n1[i][1] + n2[j][1]});
        i++;
        j++;
      }
      else if (n1[i][0] < n2[j][0])
      {
        ans.push_back({n1[i][0], n1[i][1]});
        i++;
      }
      else
      {
        ans.push_back({n2[j][0], n2[j][1]});
        j++;
      }
    }

    while (i < n)
    {
      ans.push_back({n1[i][0], n1[i][1]});
      i++;
    }

    while (j < m)
    {
      ans.push_back({n2[j][0], n2[j][1]});
      j++;
    }

    return ans;
  }
};