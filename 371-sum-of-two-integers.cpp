// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        while (b != 0) {
            // sum of the current bits, besides carry
            int x = a ^ b;
            // carry bits
            int y = (a & b) << 1;
            // the next iteration will add the carry bits onto the sum bits, until carry is zero
            a = x;
            b = y;
        }
        return a;
    }
};