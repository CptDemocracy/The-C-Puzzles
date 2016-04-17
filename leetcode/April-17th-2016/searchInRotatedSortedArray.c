/*
[ref.href] leetcode.com/problems/search-in-rotated-sorted-array
"
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  You are given a target value to search. If found in the array return its 
  index, otherwise return -1. You may assume no duplicate exists in the array.
"

SPECIAL THANKS to wiki.ruihan.org/index.php/Search_in_Rotated_Sorted_Array for
clearing the picture up for me.
*/

int search(int* nums, int numsSize, int target) {
    
    int lo = 0;
    int hi = numsSize - 1;
    int mp = (lo + hi) / 2;
    
    while (lo <= hi) {
        
        if (nums[mp] == target) return mp;
        
        if (nums[mp] < nums[hi]) {
            if (target > nums[mp] && target <= nums[hi]) {
                lo = mp + 1;
            } else {
                hi = mp - 1;
            }
        } else {
            if (target < nums[mp] && target >= nums[lo]) {
                hi = mp - 1;
            } else {
                lo = mp + 1;
            }
        }
        mp = (lo + hi) / 2;
    }
    return -1;
}
