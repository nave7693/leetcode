// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            result += (n & 1) ? 1 : 0;
            n = n >> 1;
        }
        return result;
    }
};