vector<vector<vector<int>>> dp;
class Solution {
public:



    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
       unordered_map<int,unordered_map<int,int>> dp;
        vector<int> maxAtK(k+1,0);
        for(int i=0;i<n;i++){
            for(int rk=k;rk>=0;rk--){
                dp[nums[i]][rk]=dp[nums[i]][rk]+1;
                if(rk>0) dp[nums[i]][rk]=max(dp[nums[i]][rk],1+maxAtK[rk-1]);
                maxAtK[rk]=max(dp[nums[i]][rk],maxAtK[rk]);
            }
        }
        int ans=0;
        for(int i : maxAtK){
            ans=max(ans,i);
        }
        return ans;
    }
};