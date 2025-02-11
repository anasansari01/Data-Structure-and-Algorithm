class Solution
{
public:
  // Function to check whether a Binary Tree is BST or not.
  bool isBST(Node *root)
  {
    Node *prev = nullptr;
    return check(root, prev);
  }

private:
  bool check(Node *root, Node *&prev)
  {
    if (!root)
      return true;

    if (!check(root->left, prev))
      return false;
    if (prev != nullptr && root->data <= prev->data)
      return false;

    prev = root;
    return check(root->right, prev);
  }
};