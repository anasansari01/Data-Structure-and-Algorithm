class Solution
{
public:
  bool check(Node *root, unordered_map<int, int> &mp, int target)
  {
    if (!root)
      return false;

    if (check(root->left, mp, target))
      return true;

    int val = target - root->data;

    if (mp.find(val) != mp.end())
      return true;

    mp[root->data] = 1;

    return check(root->right, mp, target);
  }

  bool findTarget(Node *root, int target)
  {
    unordered_map<int, int> mp;

    return check(root, mp, target);
  }
};