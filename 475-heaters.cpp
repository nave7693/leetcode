// https://leetcode.com/problems/heaters

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        
        for (int i = 0; i < houses.size(); i++) {
            auto heaterAfter = std::upper_bound(heaters.begin(), heaters.end(), houses[i]);
            int distAfter = (heaterAfter == heaters.end()) ? INT_MAX : *heaterAfter - houses[i];
            auto heaterBefore = (heaterAfter == heaters.begin()) ? heaters.end() : heaterAfter - 1;
            int distBefore = (heaterBefore == heaters.end()) ? INT_MAX : houses[i] - *heaterBefore;
            result = max(result, min(distBefore, distAfter));
        }
        return result;
    }
};