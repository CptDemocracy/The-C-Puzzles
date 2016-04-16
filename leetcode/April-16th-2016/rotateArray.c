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
