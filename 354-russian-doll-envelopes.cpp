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