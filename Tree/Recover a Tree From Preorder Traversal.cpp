/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *recoverFromPreorder(string t)
  {
    stack<TreeNode *> s;

    int idx = 0;

    while (idx < t.size())
    {

      int d = 0;
      while (idx < t.size() && t[idx] == '-')
      {
        d++;
        idx++;
      }

      int val = 0;
      while (idx < t.size() && isdigit(t[idx]))
      {
        val = val * 10 + (t[idx] - '0');
        idx++;
      }

      TreeNode *node = new TreeNode(val);

      while (s.size() > d)
      {
        s.pop();
      }

      if (!s.empty())
      {

        if (s.top()->left == nullptr)
        {
          s.top()->left = node;
        }
        else
        {
          s.top()->right = node;
        }
      }

      s.push(node);
    }

    while (s.size() > 1)
      s.pop();

    return s.top();
  }
};