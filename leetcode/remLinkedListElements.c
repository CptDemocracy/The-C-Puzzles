/*
[ref.href] leetcode.com/problems/remove-linked-list-elements
"
  Remove all elements from a linked list of integers that have value val.
  
  Example
  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
  Return: 1 --> 2 --> 3 --> 4 --> 5
  
  Credits:
  Special thanks to @mithmatt for adding this problem and creating all test cases.
"

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    while (head && head->val == val) head = head->next;
    if (!head) return NULL;
   
    struct ListNode *node = head, *next = head->next;
    while (next) {
        while (next && next->val != val) {
            node = node->next;
            next = next->next;
        }
        while (next && next->val == val) {
            next = next->next;
        }
        node->next = next;
    }

    return head;
}
