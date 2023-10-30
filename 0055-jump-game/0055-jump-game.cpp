class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        /*vector<bool> dp(nums.size(),false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i] && i+j<n;j++){
                if(dp[i+j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];*/
        int reachable=0;
        for(int i=0;i<n-1;i++){
            reachable=max(reachable,i+nums[i]);
            if(nums[i]==0 && reachable==i){
                return false;
            }
        }
        return true;
    }
};