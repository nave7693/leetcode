// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        int sign = x > 0 ? 1 : -1;
        unsigned int signless = abs(x);
        unsigned int reverse = 0;
        // Get rid of all trailing zeros
        while (signless % 10 == 0 && signless > 0) {
            signless /= 10;
        }
        while (signless > 0) {
            if (reverse > ((INT_MAX - signless % 10) / 10)) {
                return 0;
            }
            reverse *= 10;
            reverse += signless % 10;
            signless /= 10;
        }
        return reverse * sign;
    }
};