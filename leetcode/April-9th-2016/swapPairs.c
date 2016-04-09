/*
[ref.href] leetcode.com/problems/swap-nodes-in-pairs
"
  Given a linked list, swap every two adjacent nodes and return its head.
  
  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.
  
  Your algorithm should use only constant space. You may not modify the values 
  in the list, only nodes itself can be changed.
"
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* next = head->next;
    if (next) {
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
    return head;
}
