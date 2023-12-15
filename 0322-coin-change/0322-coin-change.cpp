class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,1e9));
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<amount+1;i++){
            for(int j=1;j<n+1;j++){
                if(i<coins[j-1]){
                    dp[i][j]=dp[i][j-1];
                }else{
                    dp[i][j]=min(1+dp[i-coins[j-1]][j],dp[i][j-1]);
                }
                
            }
        }
        if(dp[amount][n]==1e9) return -1;
        return dp[amount][n];
    }
};