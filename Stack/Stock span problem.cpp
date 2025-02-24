class Solution
{
public:
  vector<int> calculateSpan(vector<int> &arr)
  {
    int n = arr.size();
    stack<pair<int, int>> st;

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
      int cnt = 1;
      while (!st.empty() && st.top().first <= arr[i])
      {
        cnt += (st.top().second);
        st.pop();
      }
      st.push({arr[i], cnt});
      ans[i] = cnt;
    }
    return ans;
  }
};