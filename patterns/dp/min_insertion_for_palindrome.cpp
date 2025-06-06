// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
class Solution {
public:
    vector<vector<int>> dp= vector<vector<int>>(501, vector<int>(501));
    int LCS(string &str1, string &str2, int m, int n){
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if( i== 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j -1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
    int minInsertions(string s) {
        int n = s.length();
        string x = s;
        reverse(x.begin(), x.end());
        int lcs = LCS(s, x, n, n);
        return n - lcs;
    }
};