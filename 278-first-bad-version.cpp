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