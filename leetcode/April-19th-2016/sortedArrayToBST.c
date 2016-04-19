/*
[ref.href] leetcode.com/problems/convert-sorted-array-to-binary-search-tree
"
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize < 1) return NULL;
    int mp = numsSize / 2;
    struct TreeNode* root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (!root) return NULL;
    root->val = nums[mp];
    root->right = sortedArrayToBST(&nums[mp + 1], numsSize - mp - 1);
    root->left = sortedArrayToBST(nums, mp);
    return root;
}
