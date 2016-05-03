// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) {
            return nullptr;
        }
        if (n == 1) {
            return string("1");
        }
        string result("1");
        string temp;
        for (int i = 2; i <= n; i++) {
            int j = 0;
            while(j < result.size()) {
                int count = 0;
                int current = result[j];
                while (current == result[j] && j < result.size()) {
                    count++;
                    j++;
                }
                temp += count + '0';
                temp += current;
            }
            result = temp;
            temp = "";
        }
        return result;
    }
};