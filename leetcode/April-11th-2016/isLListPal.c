/*
[ref.href] leetcode.com/problems/palindrome-linked-list
"
    Given a singly linked list, determine if it is a palindrome.
"

SPECIAL THANKS to the owners of the resource:
    wiki.ruihan.org/index.php/All_algorithm_problems/linked_list
which provided an insight into solving this problem.
*/

int isPalindrome(struct ListNode* head) {
    if (!head) return 1;
    struct ListNode 
        *mid = head, 
        *tail = head;
    // find midp
    while (tail && tail->next) {
        mid = mid->next;
        tail = tail->next->next;
    }
    // reverse 2nd half
    struct ListNode 
        *tmp = NULL,
        *newhead = NULL,
        *curr = mid;
    while (curr) {
        tmp = curr->next;
        curr->next = newhead;
        newhead = curr;
        curr = tmp;
    }
    // see if pal
    while (1) {
        if (!head && !newhead) {
            break;
        }
        if (!head || !newhead) {
            return 0;
        }
        if (head->val != newhead->val) {
            return 0;
        }
        head = head->next;
        if (head == newhead) {
            break;
        }
        newhead = newhead->next;
    }
    return 1;
}
