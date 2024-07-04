class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins,int index,int amount){
        if(amount==0) return 1;
        if(index==coins.size()) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int ans=0;
        ans+=helper(coins,index+1,amount);
        if(amount>=coins[index]){
            ans+=helper(coins,index,amount-coins[index]);
        }
        return dp[index][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        dp=vector<vector<int>>(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,0,amount);
        return ans;
    }
};