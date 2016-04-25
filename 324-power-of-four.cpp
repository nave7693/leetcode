// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        double power = log(num)/log(4);
        return (pow(4, round(power)) == num);
    }
};