/*
[ref.href] leetcode.com/problems/remove-duplicates-from-sorted-list
"
  Given a sorted linked list, delete all duplicates such that each element 
  appear only once.
  
  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
"
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode *first = head, *second = NULL;
    int val = 0;
    while (first) {
        val = first->val;
        second = first->next;
        while (second && val == second->val) {
            second = second->next;
        }
        first->next = second;
        first = second;
    }
    return head;
}
