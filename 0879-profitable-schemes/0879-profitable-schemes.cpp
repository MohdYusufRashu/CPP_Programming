#define ll long long
class Solution {
public:
    int mod=1e9+7;
    
    int solve(int n, int minProfit, vector<int>& group, vector<int>& profit,int index,vector<vector<vector<int>>>& dp){
        if(index==profit.size()){
            if(minProfit==0) return 1;
            return 0;
        }
        if(dp[index][minProfit][n]!=-1) return dp[index][minProfit][n];
        ll ans=0;
        //include
        if(group[index]<=n){
            int p=max(0,minProfit-profit[index]);
            ans+=solve(n-group[index],p,group,profit,index+1,dp);
            ans%=mod;
        }
        //exclude
        ans+=solve(n,minProfit,group,profit,index+1,dp);
        ans%=mod;
        return dp[index][minProfit][n]=ans;   
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sz=profit.size();
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        int ans=solve(n,minProfit,group,profit,0,dp);
        return ans;
    }
};