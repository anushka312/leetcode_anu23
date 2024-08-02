// https://leetcode.com/problems/is-subsequence/
// Complexity: Time: O(m+n) Space: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int n = s.size();
        int m = t.size();
        for(int i = 0; i<m && j<n; i++){
            if(s[j] == t[i]){
                j++;
            }
        }

        return (j == n);
    }
};