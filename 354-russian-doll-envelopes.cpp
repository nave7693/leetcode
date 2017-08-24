// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    static bool sortEnvelopes(pair<int, int>& env1, pair<int, int>& env2) {
        return (env1.first < env2.first) || (env1.first == env2.first && env1.second > env2.second);
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n <= 1) return n;
        
        std::sort(envelopes.begin(), envelopes.end(), sortEnvelopes);
        
        // dp[i] = max number of envelopes when using only the first i envelopes
        vector<int> dp(n);
        int result = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

// 08/20/2017 using binarysearch to solve for Longest Increaseing Subsequence of heights on envelopes sorted on ascending widths
class Solution {
private:
    // find the index of the first number in nums that is no less than target
    int binarySearch(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
        });
        vector<int> LIS;
        for (int i = 0; i < envelopes.size(); i++) {
            int index = binarySearch(LIS, envelopes[i].second);
            if (index == -1 or index == LIS.size()) {
                LIS.push_back(envelopes[i].second);
            } else {
                LIS[index] = envelopes[i].second;
            }
        }
        return LIS.size();
    }
};