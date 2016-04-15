/*
[ref.href] leetcode.com/problems/search-insert-position
"
  Given a sorted array and a target value, return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.

  You may assume no duplicates in the array.
  
  Here are few examples:
  
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0
"
*/

int searchInsert(int* nums, int numsSize, int target) {
    if (target < nums[0]) {
        return 0;
    }
    if (target > nums[numsSize - 1]) {
        return numsSize;
    }
    int lo = 0;
    int hi = numsSize - 1;
    int mp = (lo + hi) >> 1; // (lo + hi) / 2
    while (lo <= hi) {
        if (target < nums[mp]) {
            hi = mp - 1;
        }
        else if (target > nums[mp]) {
            lo = mp + 1;
        }
        else {
            return mp;
        }
        mp = (lo + hi) >> 1; // (lo + hi) / 2
    }
    return mp + 1;
}
