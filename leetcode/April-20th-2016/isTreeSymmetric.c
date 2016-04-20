/*
[ref.href] leetcode.com/problems/symmetric-tree
"
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
  
  For example, this binary tree is symmetric:
  
      1
     / \
    2   2
   / \ / \
  3  4 4  3
  
  But the following is not:
      1
     / \
    2   2
     \   \
     3    3
"
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool areSymmetric(struct TreeNode* left, struct TreeNode* right) {
     if (!left && !right) return 1;
     if (!left || !right) return 0;
     if ((left->left && right->right && left->left->val != right->right->val)
        || (left->right && right->left && left->right->val != right->left->val))
     {
         return 0;
     }
     return areSymmetric(left->left, right->right) && areSymmetric(left->right, right->left);
 }
 
bool isSymmetric(struct TreeNode* root) {
    if (!root) return 1;
    if (!root->left && !root->right) return 1;
    if (!root->left || !root->right) return 0;
    if (root->left->val != root->right->val) return 0;
    return areSymmetric(root->left, root->right);
}
