// https://leetcode.com/problems/valid-palindrome/description/
// Solution: Time: O(n) Space: O(1)

// we first converted capital letters to lowercase letters 
// then, we created two pointers, one 'start' and other 'end'
// created 3 diff cases, where incrementing is done if either of the letters is not alphanum 
// and then check if they are the same

class Solution {
public:
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a';
        } else
            return ch;
    }
    bool isPalindrome(string s) {
        if (s == "")
            return true;
        int n = s.size();

        int st = 0;
        int e = n - 1;
        while (st <= e) {
            while (st < e && !isalnum(s[st])) {
                ++st;
            };
            while (st < e && !isalnum(s[e])) {
                --e;
            };
            while (st < e && toLower(s[st]) != toLower(s[e])) {
                return false;
            }
            ++st;
            --e;
        }

        return true;
    }
};