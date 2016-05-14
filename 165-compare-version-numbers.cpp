// https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int getNumber(string s, int *index) {
        int result = 0;
        while (*index < s.size() && s[*index] != '.') {
            result = result * 10 + s[*index] - '0';
            (*index)++;
        }
        if (s[*index] == '.') {
            (*index)++;
        }
        return result;
    }

    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        int result = 0;
        while (index1 < version1.size() || index2 < version2.size()) {
            int v1 = getNumber(version1, &index1);
            int v2 = getNumber(version2, &index2);
            if (v1 == v2) {
                continue;
            } else if (v1 < v2) {
                return -1;
            } else {
                return 1;
            }
        }
        int tail1 = version1.size() - index1;
        int tail2 = version2.size() - index2;
        if (tail1 == tail2) {
            return 0;
        } else if (tail1 < tail2) {
            return -1;
        } else if (tail1 > tail2) {
            return 1;
        }
        return 0;
    }
};