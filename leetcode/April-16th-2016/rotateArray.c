/*
[ref.href] leetcode.com/problems/rotate-array
"
    Rotate an array of n elements to the right by k steps.

    For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
    
    Credits:
    Special thanks to @Freezen for adding this problem and creating all test cases.
"
*/

void reverse(int* nums, int start, int stop) {
    if (!nums) return;
    
    int temp = 0;
    for (int i = start, j = stop - 1; i < j; ++i, --j) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (!nums) return;
    
    k = k % numsSize;
    reverse(nums, 0, numsSize - k);
    reverse(nums, numsSize - k, numsSize);
    reverse(nums, 0, numsSize);
}
