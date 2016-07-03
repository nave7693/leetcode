// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }
        
        unordered_map<int, vector<int>> freqNumbers;
        for (auto iter = frequency.begin(); iter != frequency.end(); iter++) {
            freqNumbers[iter->second].push_back(iter->first);
        }
        
        vector<int> result;
        for (int i = nums.size(); i > 0 && k > 0; i--) {
            if (freqNumbers.count(i) > 0) {
                for (int j = 0; j < freqNumbers[i].size() && k > 0; j++) {
                    result.push_back(freqNumbers[i][j]);
                    k--;
                }
            }
        }
        return result;
    }
};