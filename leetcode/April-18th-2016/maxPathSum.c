/*
[ref.href] leetcode.com/problems/binary-tree-maximum-path-sum
"
  Given a binary tree, find the maximum path sum.
  
  For this problem, a path is defined as any sequence of nodes from 
  some starting node to any node in the tree along the parent-child 
  connections. The path does not need to go through the root.
  
  For example:
  Given the below binary tree,
  
    1
   / \
  2   3
  
  Return 6.
"

SPECIAL THANKS to wiki.ruihan.org/index.php/Binary_Tree_Maximum_Path_Sum
for clarifying the problem for me.
*/

#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int maxPathSumHelper(struct TreeNode* root, int* pmax) {
    if (!root) return 0;
    if (!pmax) return 0;
    
    int left = maxPathSumHelper(root->left, pmax);
    left = left > 0 ? left : 0;
    
    int right = maxPathSumHelper(root->right, pmax);
    right = right > 0 ? right : 0;
    
    int sum = root->val + left + right;
    if (sum > *pmax) {
        *pmax = sum;
    }
    return root->val + ((left > right) ? left : right);
 }
 
int maxPathSum(struct TreeNode* root) {
    if (!root) return 0;
    int max = INT_MIN;
    maxPathSumHelper(root, &max);
    return max;
}
