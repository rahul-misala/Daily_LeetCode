class Solution {
public:
 bool subsetSum(vector<int>& nums, int s) {
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(s+1, false));
        
        for(int col = 0; col<s+1; col++) {
            dp[0][col] = false;
        }
        
        for(int row = 0; row<n+1; row++) {
            dp[row][0] = true;
        }
        
        
        for(int i = 1; i<n+1; i++) {
            for(int j = 1; j<s+1; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][s];
    }
    bool canPartition(vector<int>& nums) {
         int sum = 0;
        for(int x:nums){
            sum += x;
        }
        
        if(sum%2 != 0)
            return false;
        
        sum = sum/2;
        
        return subsetSum(nums, sum);
    }
};