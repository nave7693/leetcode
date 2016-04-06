// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int nstart = 0;
        int result = 0;
        int nend = 0;
        while(nstart + needle.size() <= haystack.size()) {
            while((nstart < haystack.size()) && (haystack[nstart] != needle[0])) {
                nstart++;
            }
            if (haystack[nstart] == needle[0]) {
                while((nstart + nend < haystack.size()) && (haystack[nstart + nend] == needle[nend])) {
                    nend++;
                }
                if (nend == needle.size()) {
                    return nstart;
                } else {
                    nstart++;
                    nend = 0;
                }
            }
        }
        return -1;
    }
};