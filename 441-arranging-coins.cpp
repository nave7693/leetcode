// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        long lo = 0;
        long hi = (long)n;
        long mid;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if ((long)n >= (1 + mid) * mid / 2) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return (int)(lo - 1);
    }
};