// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    NumArray(vector<int> &nums):
        myNums(nums)
    {
    }

    int sumRange(int i, int j) {
        int result = 0;
        for (int index = i; index <= j; index++) {
            result += myNums[index];
        }
        return result;
    }
    
private:
    vector<int> myNums;
};

// 8/1
// sumRange should be O(1)
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

class NumArray {
private:
    vector<int> myNums;
public:
    NumArray(vector<int> nums) {
        if (nums.size() > 0) {
            myNums.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                myNums.push_back(nums[i] + myNums[i-1]);
            }            
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0 || i >= myNums.size() || j >= myNums.size()) return myNums[j];
        return myNums[j] - myNums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */