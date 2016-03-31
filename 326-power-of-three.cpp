// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        
        // With a loop
        while ((n > 1) && (n % 3 == 0)) {
            n = n / 3;
        }
        return (n == 1);
        
        // Without a loop
        double power = log(n) / log(3);
        return (pow(3, round(power)) == n);
    }
};