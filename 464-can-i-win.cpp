// https://leetcode.com/problems/can-i-win

class Solution {
public:
    unordered_set<int>win, lose;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if( (maxChoosableInteger*(maxChoosableInteger+1) >> 1) < desiredTotal) return false;
        return canIWin(0, maxChoosableInteger, desiredTotal);
    }
    
    bool canIWin( int usedBits, int maxChoosableInteger, int desiredTotal)
    {
        if(desiredTotal <= 0) return false;
        if(win.find(usedBits) != win.end()) return true;
        if(lose.find(usedBits) != lose.end()) return false;
        for(int i = maxChoosableInteger; i > 0; i-- )
        {
            int bit = 1 << i;
            if(usedBits & bit) continue;
            if(!canIWin(usedBits | bit, maxChoosableInteger, desiredTotal - i))
            {
                win.insert(usedBits);
                return true;
            }
        }
        lose.insert(usedBits);
        return false;
    }
};