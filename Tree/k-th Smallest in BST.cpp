class Solution
{
public:
  void solve(Node *root, vector<int> &v)
  {
    if (!root)
      return;

    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
  }
  // Return the Kth smallest element in the given BST
  int kthSmallest(Node *root, int k)
  {
    vector<int> v;
    solve(root, v);
    if (v.size() < k)
      return -1;
    sort(v.begin(), v.end());

    return v[k - 1];
  }
};