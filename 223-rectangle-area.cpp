// https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C - A) * (D - B) + (G - E) * (H - F);
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        if (left < right && bottom < top) {
            result -= (right - left) * (top - bottom);
        }
        return result;
    }
};