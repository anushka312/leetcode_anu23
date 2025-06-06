// https://leetcode.com/problems/shortest-common-supersequence/description/
class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001));
    string LCS(string& str1, string& str2, int m, int n) {
        string ans = "";
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    ans.push_back(str2[j-1]);
                    j--;
                } else {
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i > 0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        string lcs = LCS(str1, str2, m, n);
        
        return lcs;
    }
};