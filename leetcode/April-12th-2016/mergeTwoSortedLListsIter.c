/*
[ref.href] leetcode.com/problems/merge-two-sorted-lists
"
  Merge two sorted linked lists and return it as a new list. The new list
  should be made by splicing together the nodes of the first two lists.
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
    struct ListNode dummy = { .val = 0, .next = NULL },
        *curr = &dummy;
    while (l1 || l2) {
        if (!l1) {
            curr->next = l2;
            l2 = l2->next;
        }
        else if (!l2) {
            curr->next = l1;
            l1 = l1->next;
        }
        else if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        }
        else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    return dummy.next;
}
