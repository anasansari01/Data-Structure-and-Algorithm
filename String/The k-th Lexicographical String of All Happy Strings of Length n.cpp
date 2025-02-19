class Solution
{
public:
  string getHappyString(int n, int k)
  {
    string currString = "";
    vector<string> happyString;

    generate(n, happyString, currString);

    if (happyString.size() < k)
      return "";

    sort(happyString.begin(), happyString.end());

    return happyString[k - 1];
  }

private:
  void generate(int n, vector<string> &happyString, string currString)
  {
    if (currString.size() == n)
    {
      happyString.push_back(currString);
      return;
    }

    for (char currChar = 'a'; currChar <= 'c'; currChar++)
    {

      if (currString.size() > 0 && currString.back() == currChar)
        continue;

      generate(n, happyString, currString + currChar);
    }
  }
};