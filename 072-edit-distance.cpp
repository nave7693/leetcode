// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        if (l1 == 0) { return l2; }
        if (l2 == 0) { return l1; }
        
        // mindist[i][j] = edit distance from word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> mindist(l1 + 1, vector<int>(l2 + 1, 0));
        
        // base cases where either strings are empty
        for (int i = 1; i <= l1; i++) {
            mindist[i][0] = i;
        }
        for (int j = 1; j <= l2; j++) {
            mindist[0][j] = j;
        }
        
        // edit distance is the same if current chars are equal, otherwise it is
        // the smallest of either insert a char (i - 1) , delete a char (j - 1), or replace a char (both i-1 and j-1)
        // and adding the extra distance 1 for this operation.
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    mindist[i][j] = mindist[i-1][j-1];
                } else {
                    mindist[i][j] = min(min(mindist[i-1][j], mindist[i][j-1]), mindist[i-1][j-1]) + 1;
                }
            }
        }
        return mindist[l1][l2];
    }
};
