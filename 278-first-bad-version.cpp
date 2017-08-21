// https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersionWorker(int low, int high) {
        if (low == high) {
            return low;
        } else {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                return firstBadVersionWorker(low, mid);
            } else {
                return firstBadVersionWorker(mid+1, high);
            }
        }
    }

    int firstBadVersion(int n) {
        return firstBadVersionWorker(0, n);
    }
};

// 08/20/2017
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};