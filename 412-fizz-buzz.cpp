// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(0);
        if (n >= 1) {
            for (int i = 1; i <= n; i++) {
                if (i % 3 != 0 && i % 5 != 0) {
                    result.push_back(std::to_string(i));
                } else {
                    if (i % 15 == 0) {
                        result.push_back("FizzBuzz");
                    } else if (i % 3 == 0) {
                        result.push_back("Fizz");
                    } else {
                        result.push_back("Buzz");
                    }
                }
            }
        }
        return result;
    }
};