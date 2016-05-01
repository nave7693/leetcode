// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int seen[10] = {};
        
        for (int i = 0; i < secret.size(); i++) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g) {
                bulls++;
            } else {
                if (seen[s] < 0) cows++;
                if (seen[g] > 0) cows++;
                seen[g]--;
                seen[s]++;
            }
        }
        string result;
        result += to_string(bulls);
        result += 'A';
        result += to_string(cows);
        result += 'B';
        return result;
    }
};