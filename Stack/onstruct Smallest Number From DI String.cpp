class Solution
{
public:
  string smallestNumber(string pattern)
  {
    stack<int> st;
    string result = "";
    int num = 1;

    for (int i = 0; i <= pattern.size(); i++)
    {
      st.push(num++);
      if (i == pattern.size() || pattern[i] == 'I')
      {
        while (!st.empty())
        {
          result += to_string(st.top());
          st.pop();
        }
      }
    }

    return result;
  }
};