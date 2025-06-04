// https://leetcode.com/problems/partition-equal-subset-sum/description/
// TC -> O(n2) SC -> O(n2)
class Solution {
public:
    bool subsetSum(vector<int>& nums, int ans){
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(ans + 1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<ans + 1; j++){
                
                if(i == 0){
                    dp[i][j] = false;
                }
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<ans+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j- nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return dp[n][ans];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }

        return subsetSum(nums, sum/2);
    }
};