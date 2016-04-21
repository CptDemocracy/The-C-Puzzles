/*
[ref.href] leetcode.com/problems/validate-binary-search-tree
"
  Given a binary tree, determine if it is a valid binary search tree (BST).

  Assume a BST is defined as follows:
  
  The left subtree of a node contains only nodes with keys less than the node's key.
  The right subtree of a node contains only nodes with keys greater than the node's key.
  Both the left and right subtrees must also be binary search trees.
"

SPECIAL THANKS to wiki.ruihan.org/index.php/Validate_Binary_Search_Tree for clarifying
the problem.
*/

#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool isValidBSTHelper(struct TreeNode* root, long long min, long long max) {
    if (!root) return true;
    
    long long value = root->val;
    if (value > min && value < max) {
        return isValidBSTHelper(root->left, min, value) && isValidBSTHelper(root->right, value, max);
    } 
    return false;
}

bool isValidBST(struct TreeNode* root) {
    if (!root) return true;
    
    long long min = (long long)INT_MIN - 1LL;
    long long max = (long long)INT_MAX + 1LL;
    
    return isValidBSTHelper(root, min, max);
}
