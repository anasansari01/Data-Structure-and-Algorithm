class Solution
{
  static bool cmp1(vector<int> &a, vector<int> &b)
  {
    return a[1] < b[1];
  }
  static bool cmp2(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }

public:
  int find(int n, vector<vector<int>> &rectangles)
  {

    int regions = 0;
    long long int prev = 1ll * rectangles[0][1] + 1;

    for (vector<int> &rectangle : rectangles)
    {

      if (1ll * rectangle[1] < prev)
      {
        prev = max(prev, 1ll * rectangle[3]);
      }
      else
      {
        regions++;
        if (prev > 1ll * n)
        {
          return 0;
        }
        prev = 1ll * rectangle[3];
      }

      if (regions == 2)
      {
        return 1;
      }
    }

    return regions == 2;
  }
  int find2(int n, vector<vector<int>> &rectangles)
  {

    int regions = 0;
    long long int prev = 1ll * rectangles[0][0] + 1;

    for (vector<int> &rectangle : rectangles)
    {

      if (1ll * rectangle[0] < prev)
      {
        prev = max(prev, 1ll * rectangle[2]);
      }
      else
      {
        regions++;
        if (prev > 1ll * n)
        {
          return 0;
        }
        prev = 1ll * rectangle[2];
      }

      if (regions == 2)
      {
        return 1;
      }
    }

    return regions == 2;
  }
  bool checkValidCuts(int n, vector<vector<int>> &rectangles)
  {

    sort(rectangles.begin(), rectangles.end(), cmp1);

    int ans = find(n, rectangles);

    if (ans)
    {
      return 1;
    }

    sort(rectangles.begin(), rectangles.end(), cmp2);

    return find2(n, rectangles);
  }
};