// https://leetcode.com/problems/target-sum/
// TC -> O(n2), SC -> O(n2) approx

class Solution {
public:
    int countSubsetSum(vector<int>& nums, int ans){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(ans+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<ans +1; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                if( j ==0 ){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<ans+1; j++){
                 if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                 }else{
                    dp[i][j] = dp[i-1][j];
                 }
            }
        }

        return dp[n][ans];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        int ans = (target + sum)/2;
        if((target + sum)%2 != 0 || sum < abs(target)){
            return 0;
        }
        return countSubsetSum(nums, ans);
    }
};