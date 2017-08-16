// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 0) return INT_MIN;
        
        int left = 1;
        int right = INT_MAX;
        while (true) {
            int mid = left + (right - left) / 2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x/(mid+1))
                    return mid;
                left = mid + 1;
            }
        }
    }
};

// Newton's method
class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while (r*r > x)
            r = (r + x/r) >> 1;
        return r;
    }
};