class Solution {
public:
    int trailingZeroes(int n) {
        // Only need to care how many 5s comprise n!
        // We need to add up all the numbers that factor with one 5, two 5s, three 5s, so on.
        int result = 0;
        int nextn = n;
        while (nextn >= 5)
        {
            result += nextn / 5;
            nextn /= 5;
        }
        return result;
    }
};