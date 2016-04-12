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
    if (!l1 && !l2) {
        return NULL;
    }
    else if (!l1) {
        return l2;
    }
    else if (!l2) {
        return l1;
    }
    struct ListNode* head = NULL;
    if (l1->val < l2->val) {
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    } else {
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }
    return head;
}
