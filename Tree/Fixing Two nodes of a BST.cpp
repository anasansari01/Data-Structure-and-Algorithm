class Solution
{
  Node *prev = nullptr;
  Node *first = nullptr;
  Node *second = nullptr;

public:
  void correctBST(Node *root)
  {
    inorder(root);

    if (first && second)
    {
      swap(first->data, second->data);
    }
  }

private:
  void inorder(Node *root)
  {
    if (!root)
      return;

    inorder(root->left);

    if (prev && prev->data > root->data)
    {
      if (!first)
      {
        first = prev;
      }
      second = root;
    }

    prev = root;

    inorder(root->right);
  }
};