/*
[ref.href] leetcode.com/problems/reverse-bits

"
  Reverse bits of a given 32 bits unsigned integer.
  
  For example, given input 43261596 (represented in binary as 
  00000010100101000001111010011100), return 964176192 (represented 
  in binary as 00111001011110000010100101000000).
  
  Follow up:
  If this function is called many times, how would you optimize it?
  
  Credits:
  Special thanks to @ts for adding this problem and creating all test cases.
"

*/

uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    int shrcount = 0;
    while (n > 0) {
        uint32_t bit = n & 1;
        m = (bit << (31 - shrcount)) | m;
        n >>= 1; // logical shift
        ++shrcount;
    }
    return m;
}
