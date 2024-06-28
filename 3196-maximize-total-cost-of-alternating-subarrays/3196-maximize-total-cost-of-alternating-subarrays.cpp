class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1e18));
        dp[0][0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0])+nums[i];
            dp[i][1]=dp[i-1][0]+(-1*nums[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};