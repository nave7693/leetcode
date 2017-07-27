// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        // Orthodox DP
        int ls = s.length();
        int lp = p.length();
        
        // matched[i][j] = s[0..i-1] matched p[0..j-1] ? 
        // note that i=0 or j=0 indicate empty string
        vector<vector<bool>> matched(ls+1, vector<bool>(lp+1, false));
        
        // Check for all cases of '*', and indicate that a p that ends with '*' will match whatever s
        // positioned at/before that location
        matched[0][0] = true;
        for (int i = 0; i <= ls; i++) {
            for (int j = 1; j <= lp && p[j-1] == '*'; j++) {
                matched[i][j] = true;
            }            
        }
        
        // Check for other cases:
        // if pattern is '?' or matches the current char of s, then the match result is the same as match[i-1][j-1]
        // if pattern is '*' it will either match s without the '*' (repeated zero times) or it will match s sans the last char (repeated one or more times)
        for (int i = 1; i <= ls; i++) {
            for (int j = 1; j <= lp; j++) {
                if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    matched[i][j] = matched[i-1][j-1];
                } else if (p[j-1] == '*') {
                    matched[i][j] = matched[i][j-1] || matched[i-1][j];
                }
            }
        }
        return matched[ls][lp];
    }
};

// Cool dude does it in linear time and constant space...
bool isMatch(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length 
        if ((*p=='?')||(*p==*s)){s++;p++;continue;} 
   
        // * found in pattern, track index of *, only advancing pattern pointer 
        if (*p=='*'){star=p++; ss=s;continue;} 

        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        if (star){ p = star+1; s=++ss;continue;} 

        //current pattern pointer is not star, last patter pointer was not *
        //characters do not match
        return false;
    }

    //check for remaining characters in pattern
    while (*p=='*'){p++;}

    return !*p;  
}