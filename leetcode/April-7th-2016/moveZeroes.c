/*
[ref.href] leetcode.com/problems/move-zeroes

"
  Given an array nums, write a function to move all 0's to the end of it while maintaining 
  the relative order of the non-zero elements.
  
  For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be 
  [1, 3, 12, 0, 0].
  
  Note:
  - You must do this in-place without making a copy of the array.
  - Minimize the total number of operations.
  
  Credits:
  Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
"
*/

void moveZeroes(int* nums, int numsSize) {
    if (numsSize < 1) return;
    int i = 0;
    int j = 0;
    int nonzcount = 0;
    while (j < numsSize) {
        if (nums[j] != 0) {
            nums[i] = nums[j];
            ++i, ++nonzcount;
        }
        ++j;
    }
    while (nonzcount < numsSize) {
        nums[nonzcount] = 0;
        ++nonzcount;
    }
}
