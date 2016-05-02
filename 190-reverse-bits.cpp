// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < sizeof(uint32_t) * 8; i++) {
            result = result << 1 | (n & 1);
            n = n >> 1;
        }
        return result;
    }
};