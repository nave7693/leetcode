// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    bool isVowel(char c) {
        char check = tolower(c);
        return (check == 'a') || (check == 'e') || (check == 'i') || (check == 'o') || (check == 'u');
    }

    string reverseVowels(string s) {
        int front = 0;
        int back = s.size() - 1;
        while (front < back) {
            while (!isVowel(s[front]) && (front < back)) {
                front++;
            }
            while (!isVowel(s[back]) && (front < back)) {
                back--;
            }
            if (front < back) {
                char temp = s[front];
                s[front] = s[back];
                s[back] = temp;
                front++;
                back--;
            }
        }
        return s;
    }
};