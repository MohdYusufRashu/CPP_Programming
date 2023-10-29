class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),-1);
        dp[n-1]=0;
        int ans=INT_MAX;
        for(int i=n-2;i>=0;i--){ 
            ans=INT_MAX;
            for(int j=1;j<=nums[i] && (i+j<n);j++){
                if(dp[i+j]!=-1){
                    ans=min(ans,1+dp[i+j]);
                }
            }
            if(ans!=INT_MAX) dp[i]=ans;  
        }
        return dp[0];
    }
};