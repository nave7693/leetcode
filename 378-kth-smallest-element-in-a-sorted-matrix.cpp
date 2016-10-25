// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int, int> seen;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                seen[matrix[i][j]]++;
            }
        }
        int result = 0;
        for (auto iter = seen.begin(); iter != seen.end(); iter++) {
            k -= iter->second;
            if (k <= 0) {
                result = iter->first;
                break;
            }
        }
        return result;
    }
};