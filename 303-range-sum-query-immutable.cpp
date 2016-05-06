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


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);