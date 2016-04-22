// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(0);
        int temp[numRows + 3] = {};
        temp[1] = 1;
        if (numRows == 0) {
            return result;
        }
        if (numRows >= 1) {
            result.push_back(vector<int>(temp + 1, temp + 2));
        } 
        if (numRows > 1) {
            for (int currentRow = 2; currentRow <= numRows; currentRow++) {
                int calcIndex; // +1 for the zero up front
                for (calcIndex = currentRow + 1; calcIndex >= 1; calcIndex --) {
                  temp[calcIndex] = temp[calcIndex] + temp[calcIndex - 1];
                }
                result.push_back(vector<int>(temp + 1, temp + 1 + currentRow));
            }
        }
        return result;
    }
};
