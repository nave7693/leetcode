// https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    Solution(vector<int> nums) {
        myNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return myNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // The Fisher-Yates shuffle
        vector<int> result = myNums;
        for (int i = 0; i < myNums.size(); i++) {
            int swapPos = rand() % (myNums.size() - i);
            swap(result[i + swapPos], result[i]);
        }
        return result;
    }
    
private:
    vector<int> myNums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */