// https://leetcode.com/problems/remove-outermost-parentheses/description/
// Complexity: Time: O(n) Space: O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> Stack;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (!Stack.empty()) {
                    ans.push_back(s[i]);
                }
                Stack.push(s[i]);
            } else {
                Stack.pop();
                if (!Stack.empty()) {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
