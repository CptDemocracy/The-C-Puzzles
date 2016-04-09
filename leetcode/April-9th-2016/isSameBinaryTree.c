/*
[ref.href] leetcode.com/problems/same-tree
"
  Given two binary trees, write a function to check 
  if they are equal or not.

  Two binary trees are considered equal if they are 
  structurally identical and the nodes have the same value.
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) return 1;
    if (!p || !q) return 0;
    
    return p->val == q->val 
        && isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
}
