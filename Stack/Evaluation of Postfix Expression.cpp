class Solution
{
public:
  int evaluate(vector<string> &arr)
  {
    stack<int> s;

    for (string &val : arr)
    {

      if (isdigit(val[0]) || (val.size() > 1 && val[0] == '-' && isdigit(val[1])))
      {
        s.push(stoi(val));
      }
      else
      {

        int fst = s.top();
        s.pop();
        int snd = s.top();
        s.pop();

        if (val == "+")
          s.push(snd + fst);
        else if (val == "-")
          s.push(snd - fst);
        else if (val == "*")
          s.push(snd * fst);
        else if (val == "/")
          s.push(snd / fst);
      }
    }

    return s.top();
  }
};