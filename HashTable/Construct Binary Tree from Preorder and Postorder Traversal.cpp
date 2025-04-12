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
  TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
  {
    unordered_map<int, int> postorderMap;
    for (int i = 0; i < postorder.size(); i++)
    {
      postorderMap[postorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postorderMap);
  }

private:
  TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &postorderMap)
  {
    if (preStart > preEnd || postStart > postEnd)
    {
      return nullptr;
    }

    int rootVal = preorder[preStart];
    TreeNode *root = new TreeNode(rootVal);

    if (preStart == preEnd)
    {
      return root;
    }

    int leftRootVal = preorder[preStart + 1];
    int postIndex = postorderMap[leftRootVal];
    int leftSubtreeSize = postIndex - postStart + 1;

    root->left = buildTree(preorder, preStart + 1, preStart + leftSubtreeSize, postorder, postStart, postIndex, postorderMap);
    root->right = buildTree(preorder, preStart + leftSubtreeSize + 1, preEnd, postorder, postIndex + 1, postEnd - 1, postorderMap);

    return root;
  }
};