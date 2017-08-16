// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double temp = (n < 0) ? 1/x : x;
        unsigned long long p = (n < 0) ? -n : n; // This handles INT_MIN... but it's cheating!
        while (p > 0) {
            if (p % 2) {
                result *= temp;
            }
            p = p >> 1;
            temp *= temp;
        }
        return result;
    }
};