// https://leetcode.com/problems/frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
        return canCrossHelper(stones);
    }            

private:
    unordered_map<int, bool> dp;

    bool canCrossHelper(vector<int>& stones, int pos = 0, int k = 0) {
        int key = pos | k << 11;

        if (dp.count(key) > 0)
            return dp[key];

        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1)
                continue;
            if (gap > k + 1)
                return dp[key] = false;
            if (canCrossHelper(stones, i, gap))
                return dp[key] = true;
        }

        return dp[key] = (pos == stones.size() - 1);
    }
};