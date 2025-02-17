class Solution
{
public:
  vector<int> kLargest(vector<int> &arr, int k)
  {
    sort(arr.begin(), arr.end(), [](int &a, int &b)
         { return a > b; });

    vector<int> v;

    for (int i = 0; i < k; i++)
    {
      v.push_back(arr[i]);
    }

    return v;
  }
};