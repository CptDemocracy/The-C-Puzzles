/*
[ref.href] leetcode.com/problems/remove-duplicates-from-sorted-array

"
  Given a sorted array, remove the duplicates in place such that each 
  element appear only once and return the new length.
  
  Do not allocate extra space for another array, you must do this in 
  place with constant memory.
  
  For example,
  Given input array nums = [1,1,2],
  
  Your function should return length = 2, with the first two elements 
  of nums being 1 and 2 respectively. It doesn't matter what you leave 
  beyond the new length.
"

*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    int i = 1;
    int j = 1;
    int count = 1;
    while (j < numsSize) {
        if (nums[j] == nums[j - 1]) {
            ++j;
        } else {
            nums[i] = nums[j];
            ++i, ++j, ++count;
        }
    }
    return count;
}
