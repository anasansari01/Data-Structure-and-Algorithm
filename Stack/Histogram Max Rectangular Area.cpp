class Solution
{
public:
  int getMaxArea(vector<int> &arr)
  {
    stack<int> s;
    int n = arr.size();
    int maxArea = 0;
    int i = 0;

    while (i < n)
    {
      if (s.empty() || arr[i] >= arr[s.top()])
      {
        s.push(i);
        i++;
      }
      else
      {
        int top = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        int area = arr[top] * width;
        maxArea = max(maxArea, area);
      }
    }

    while (!s.empty())
    {
      int top = s.top();
      s.pop();
      int width = s.empty() ? i : i - s.top() - 1;
      int area = arr[top] * width;
      maxArea = max(maxArea, area);
    }

    return maxArea;
  }
};