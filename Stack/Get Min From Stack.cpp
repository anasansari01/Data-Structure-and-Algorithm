class Solution
{
public:
  stack<int> s;
  int minEle = INT_MAX;
  Solution() {}

  // Add an element to the top of Stack
  void push(int x)
  {
    if (!s.empty())
    {
      if (x < minEle)
      {
        s.push(2 * x - minEle);
        minEle = x;
      }
      else
      {
        s.push(x);
      }
    }
    else
    {
      s.push(x);
      minEle = x;
    }
  }

  // Remove the top element from the Stack
  void pop()
  {
    if (s.empty())
      return;
    int y = s.top();
    s.pop();
    if (y < minEle)
    {
      minEle = 2 * minEle - y;
    }
  }

  // Returns top element of the Stack
  int peek()
  {
    return s.empty() ? -1 : (s.top() < minEle) ? minEle
                                               : s.top();
  }

  // Finds minimum element of Stack
  int getMin()
  {
    return s.empty() ? -1 : minEle;
  }
};