/*
[ref.href] leetcode.com/problems/flatten-binary-tree-to-linked-list

"
    Given a binary tree, flatten it to a linked list in-place.
"
*/


#define INIT_STACK_CAPACITY 4
#define INIT_NODES_CAPACITY 4

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (!root) return;
    
    struct TreeNode** stack = (struct TreeNode**)calloc(INIT_STACK_CAPACITY, sizeof(struct TreeNode*));
    if (!stack) return;
    
    stack[0] = root;
    
    int stackCount = 1;
    int stackCapacity = INIT_STACK_CAPACITY;
    
    struct TreeNode** nodes = (struct TreeNode**)calloc(INIT_NODES_CAPACITY, sizeof(struct TreeNode*));
    if (!nodes) return;
    
    int nodesCount = 0;
    int nodesCapacity = INIT_NODES_CAPACITY;
    
    struct TreeNode* node = NULL;
    
    while (stackCount > 0) {
        node = stack[stackCount - 1];
        --stackCount;
        
        if (nodesCount >= nodesCapacity) {
            int newNodesCapacity = nodesCapacity * 2;
            struct TreeNode** newNodes = (struct TreeNode**)calloc(newNodesCapacity, sizeof(struct TreeNode*));
            if (!newNodes) {
                return;
            }
            memcpy(newNodes, nodes, nodesCount * sizeof(struct TreeNode*));
            free(nodes);
            nodes = newNodes;
            nodesCapacity = newNodesCapacity;
        }
        nodes[nodesCount] = node;
        ++nodesCount;
    
        int childrenCount = 0;
        if (node->left) ++childrenCount;
        if (node->right) ++childrenCount;
        
        if (childrenCount > 0) {
            if (stackCount + childrenCount >= stackCapacity) {
                int newStackCapacity = (stackCount + childrenCount > stackCapacity * 2) ?
                    stackCount + childrenCount : stackCapacity * 2;
                struct TreeNode** newStack = (struct TreeNode**)calloc(newStackCapacity, sizeof(struct TreeNode*));
                if (!newStack) {
                    return;
                }
                memcpy(newStack, stack, stackCount * sizeof(struct TreeNode*));
                free(stack);
                stack = newStack;
                stackCapacity = newStackCapacity;
            }
            if (node->right) {
                stack[stackCount] = node->right;
                ++stackCount;
            }
            if (node->left) {
                stack[stackCount] = node->left;
                ++stackCount;
            }
        }
    }
    
    for (int i = 0; i < nodesCount; ++i) {
        node = nodes[i];
        if (i == nodesCount) {
            node->right = NULL;
        }
        else {
            node->right = nodes[i + 1];
        }
        node->left = NULL;
    }
    
    free(stack);
    free(nodes);
}
