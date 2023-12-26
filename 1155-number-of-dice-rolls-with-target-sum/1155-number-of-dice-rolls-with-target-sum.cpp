class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        int m=1e9+7;
        for(int i=1;i<=n;i++){ 
            for(int j=1;j<=target;j++){
                int count=0;
                for(int x=1;x<=k;x++){
                    if(j-x<0) continue;
                    count+=dp[i-1][j-x];
                    count=count%m;
                }
                dp[i][j]=count;
            }
        }
        return dp[n][target];
    }
};