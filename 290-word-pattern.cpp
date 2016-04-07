// https://leetcode.com/problems/word-pattern/

// The key is to know of the existance of istringstream that makes splitting the match target string much easier

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, bool> seen;
        map<string, int> strings;
        istringstream source(str);
        string temp;
        int index = 0;
        
        while (source >> temp) {
            if (index == pattern.size()) {
                return false;
            }
            if ((seen.find(pattern[index]) == seen.end()) != (strings.find(temp) == strings.end())) {
                return false;
            }
            seen[pattern[index]] = true;
            strings[temp]++;
            index++;
        }
        if (index < pattern.size()) {
            return false;
        }
        return true;
    }
};