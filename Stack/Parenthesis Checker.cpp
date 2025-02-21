class Solution
{
public:
  bool isBalanced(string &s)
  {
    stack<char> st;

    for (char &c : s)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        st.push(c);
      }
      else if (c == ')' || c == '}' || c == ']')
      {
        if (st.empty())
        {
          return false;
        }

        char top = st.top();
        st.pop();

        if ((top == '(' && c != ')') ||
            (top == '{' && c != '}') ||
            (top == '[' && c != ']'))
        {
          return false;
        }
      }
    }

    return st.empty();
  }
};