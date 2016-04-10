/*
[ref.href] leetcode.com/problems/merge-two-sorted-lists
"
  Merge two sorted linked lists and return it as a new list. 
  The new list should be made by splicing together the nodes of the first two lists.
"
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && !l2) return NULL;
    
    struct ListNode* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    if (!l3) return NULL;
    
    if (!l1) {
        l3->val = l2->val;
        l3->next = mergeTwoLists(NULL, l2->next);
    }
    else if (!l2) {
        l3->val = l1->val;
        l3->next = mergeTwoLists(l1->next, NULL);
    }
    else if (l1->val > l2->val) {
        l3->val = l2->val;
        l3->next = mergeTwoLists(l1, l2->next);
    }
    else {
        l3->val = l1->val;
        l3->next = mergeTwoLists(l1->next, l2);
    }
    
    return l3;
}
