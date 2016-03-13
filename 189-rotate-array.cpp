// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0)
        {
            return;
        }

        // Solution 1, O(n) runtime, O(2n) storage
        k = k % n;
        vector<int> temp;
        for (int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }
        for (int i = 0; i < n - k; i++) {
            temp.push_back(nums[i]);
        }
        nums.swap(temp);
        
        // Solution 2, O(k) runtime, O(n+k) storage
        k = k % n;
        for (int i = 0; i < k; i++) {
            nums.insert(nums.begin(), nums[nums.size() - 1 - i]);
        }
        nums.resize(n);
        
        // Solution 3, O(n) runtime, O(1) storage
        int temp;
        for (int i = 0; i < gcd(n, k); i++) {
            int j = (i + k) % n;
            temp = nums[i];
            do {
                swap(nums[j], temp);
                j = (j + k) % n;
            } while (j != i);
            nums[j] = temp;
        }
    }
};