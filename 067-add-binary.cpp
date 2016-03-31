// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string longer = a.size() > b.size() ? a : b;
        string shorter = a.size() > b.size() ? b : a;
        int ilonger = longer.size() - 1;
        int ishorter = shorter.size() - 1;
        bool carry = false;
        
        while (ishorter >= 0)
        {
            if (longer[ilonger] == '0' && shorter[ishorter] == '0') { longer[ilonger] = carry? '1' : '0'; carry = false; }
            else if (longer[ilonger] != shorter[ishorter]) { longer[ilonger] = carry? '0' : '1'; }
            else if (longer[ilonger] == '1' && shorter[ishorter] == '1') { longer[ilonger] = carry? '1' : '0'; carry = true; }
            ilonger--;
            ishorter--;
        }
        
        while (ilonger >= 0 && carry) {
            if (longer[ilonger] == '0') {
                longer[ilonger] = '1';
                carry = false;
            } else {
                longer[ilonger] = '0';
            }
            ilonger--;
        }
        
        if (ilonger < 0 && carry) {
            longer = "1" + longer;
        }
        return longer;
    }
};