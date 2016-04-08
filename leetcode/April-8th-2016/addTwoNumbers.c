/*
[ref.href] leetcode.com/problems/add-two-numbers
"
  You are given two linked lists representing two non-negative numbers. 
  The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
"
*/

/*  
    My solution works with total sums (the sum of the two numbers in the linked lists) where sum <= LLONG_MAX.
    This limit is imposed in the name of efficiency. As of now, the algorithm reads digits from the linked
    lists, converts them to a number and uses the ALU to sum the numbers.
    
    We could lift the restriction by introducing an algorithm that sums the values represented as separate
    digits in a list, however, that would increase overall overhead of the program.
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *node1 = l1, *node2 = l2;
    
    long long num1 = 0, num2 = 0;
    long long mul1 = 1, mul2 = 1;
    while (node1 || node2) {
        if (node1) {
            num1 = num1 + node1->val * mul1;
            mul1 *= 10;
            node1 = node1->next;
        }
        if (node2) {
            num2 = num2 + node2->val * mul2;
            mul2 *= 10;
            node2 = node2->next;        
        }
    }
    
    long long result = num1 + num2;
    
    size_t digcount = 0;
    long long digits = result;
    do {
        ++digcount;
        digits /= 10;
    } while (digits > 0);
    
    struct ListNode** pl3 = (struct ListNode**)calloc(digcount, sizeof(struct ListNode*));
    if (!pl3) return NULL;
    
    pl3[0] = (struct ListNode*)calloc(1, sizeof(struct ListNode*));

    size_t i = 0;
    while (i < digcount - 1) {
        if (!pl3[i]) return NULL;
        pl3[i]->val = result % 10;
        result /= 10;
        pl3[i + 1] = (struct ListNode*)calloc(1, sizeof(struct ListNode*));
        pl3[i]->next = pl3[i + 1];
        ++i;
    }
    pl3[i]->val = result % 10;
    pl3[i]->next = NULL;

    return pl3[0];
}
