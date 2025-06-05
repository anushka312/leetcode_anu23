// https://leetcode.com/problems/longest-common-subsequence/description/
// TC -> O(m*n) SC -> ideally O(M*N) but we took a constant size array

class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001, -1)); 
    int LCS(string &text1, string &text2, int m, int n){
        
        for(int i= 0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
            }
        }

        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        return LCS(text1, text2, m, n);
    }
};