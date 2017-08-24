// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return true;
        int lo = 0, hi = num, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid == num / mid) {
              return num % mid == 0;  
            }
            if (mid < (num / mid) && (mid + 1) > num / (mid + 1)) return false;
            if (num / mid < mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};

// Newton's method for sqrt
public boolean isPerfectSquare(int num) {
    long x = num;
    while (x * x > num) {
        x = (x + num / x) >> 1;
    }
    return x * x == num;
}