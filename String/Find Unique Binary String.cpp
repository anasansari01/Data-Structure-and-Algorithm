class Solution
{
public:
  string findDifferentBinaryString(vector<string> &nums)
  {
    string ans = "";
    int n = nums[0].size();

    unordered_set<string> numSet(nums.begin(), nums.end());
    generate(n, numSet, ans);
    return ans;
  }

private:
  bool generate(int n, unordered_set<string> &nums, string &ans)
  {
    if (ans.size() == n)
    {
      if (nums.find(ans) == nums.end())
      {
        return true;
      }
      return false;
    }

    for (char c : {'0', '1'})
    {
      ans.push_back(c);
      if (generate(n, nums, ans))
        return true;
      ans.pop_back();
    }

    return false;
  }
};