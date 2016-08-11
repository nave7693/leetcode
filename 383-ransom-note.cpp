// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() == 0 && ransomNote.size() != 0) {
            return false;
        }
        if (magazine.size() < ransomNote.size()) {
            return false;
        }
        map<char, int> occurences;
        for (int i = 0; i < magazine.size(); i++) {
            if (occurences.find(magazine[i]) == occurences.end()) {
                occurences[magazine[i]] = 1;
            } else {
                occurences[magazine[i]]++;
            }
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (occurences.find(ransomNote[i]) == occurences.end()) {
                return false;
            } else if (occurences[ransomNote[i]] == 0) {
                return false;
            } else {
                occurences[ransomNote[i]]--;
            }
        }
        return true;
    }
};