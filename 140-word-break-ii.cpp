// https://leetcode.com/problems/word-break-ii

class Solution {
private:
    unordered_map<string, vector<string>> memo;
    
    // We can modify prefixes in-place because wordBreak() passes us a fresh vector every time.
    vector<string> appendToStrings(string tail, vector<string> prefixes) {
        for (int i = 0; i < prefixes.size(); i++) {
            prefixes[i] = prefixes[i] + " " + tail;
        }
        return prefixes;
    }
    
    bool findString(string target, vector<string>& dict) {
        for (int i = 0; i < dict.size(); i++) {
            if (target.length() == dict[i].length() && target == dict[i]) {
                return true;
            }
        }
        return false;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int slen = s.length();
        if (memo.count(s)) return memo[s]; // cuts down on the number of recursions
        vector<string> sentences;
        if (findString(s, wordDict)) {
            sentences.push_back(s);
        }
        
        for (int i = 1; i < slen; i++) {
            string rightcut = s.substr(i);
            if (findString(rightcut, wordDict)) {
                string leftcut = s.substr(0, i);
                vector<string> combinations = appendToStrings(rightcut, wordBreak(leftcut, wordDict));
                sentences.insert(sentences.end(), combinations.begin(), combinations.end());
            }
        }
        memo[s] = sentences;
        return sentences;
    }
};