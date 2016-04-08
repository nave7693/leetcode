https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int temp[rowIndex + 3] = {};
        temp[1] = 1;
        int currentIndex = 0;
        if (rowIndex > 0) {
          while (currentIndex <= rowIndex) {
              int calcIndex = currentIndex + 1; // +1 for the zero up front
              for (calcIndex = currentIndex + 1; calcIndex >= 1; calcIndex --) {
                  temp[calcIndex] = temp[calcIndex] + temp[calcIndex - 1];
              }
              currentIndex++;
          }
        }
        return vector<int>(temp + 1, temp + 2 + rowIndex);
    }
};