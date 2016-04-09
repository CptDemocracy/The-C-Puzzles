/*
[ref.href] leetcode.com/problems/minimum-depth-of-binary-tree

"
  Given a binary tree, find its minimum depth.
"

SPECIAL THANKS to this resource and its owners who have laid the 
foundation to understanding this problem:
[ref.href] wiki.ruihan.org/index.php/Maximum_Depth_of_Binary_Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (!root) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);
    
    if (left == 0 && right == 0) return 1;
    else if (left == 0) return right + 1;
    else if (right == 0) return left + 1;
    return left < right ? left + 1 : right + 1;
}
