// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }
        string result = "";
        bool stop = false;
        int index = 0;
        while (!stop) {
            char compare = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (index == strs[i].size() || strs[i][index] != compare) {
                    stop = true;
                    break;
                }
            }
            if (!stop) {
                result += compare;
            }
            index++;
        }
        return result;
    }
};