/*
[ref.href] leetcode.com/problems/rotate-list
"
  Given a list, rotate the list to the right by k places, where k is non-negative.
  
  For example:
  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.
"
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) return NULL;
    struct ListNode dummy = { .val = 0, .next = head },
        *pdummy = &dummy,
        *slow = pdummy,
        *fast = pdummy;
    int count = 0;
    while (k > 0) {
        if (!fast->next) {
            k = k % count;
            fast = pdummy;
            if (!k) break;
        }
        fast = fast->next;
        --k; ++count;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    if (slow != pdummy) {
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
    }
    return head;
}
