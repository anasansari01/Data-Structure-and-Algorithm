class Solution
{
public:
  string decodedString(string &s)
  {
    stack<int> count;
    stack<string> strStack;
    string currString = "";
    int num = 0;

    for (char c : s)
    {

      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      else if (c == '[')
      {
        count.push(num);
        strStack.push(currString);
        num = 0;
        currString = "";
      }
      else if (c == ']')
      {
        string temp = currString;
        int repeat = count.top();
        count.pop();
        currString = strStack.top();
        strStack.pop();
        while (repeat--)
          currString += temp;
      }
      else
      {
        currString += c;
      }
    }

    return currString;
  }
};