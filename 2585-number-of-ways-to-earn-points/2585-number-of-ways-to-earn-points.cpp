class Solution {
public:
    int mod=1e9+7;
    
    int solve(vector<vector<int>>& types,int index,int target,int used,vector<vector<vector<int>>>& dp){
        if(target<0) return 0;
        if(target==0) return 1;
        if(index==types.size()){
            return 0;
        }
        if(dp[index][target][used]!=-1) return dp[index][target][used];
        //exclude
        long long exclude=solve(types,index+1,target,0,dp);
        //include
        long long include=0;
        if(used<types[index][0]){
            include=solve(types,index,target-types[index][1],used+1,dp);
        }
        long long ans=include + exclude;
        ans=ans%mod;
        return dp[index][target][used]=(int)ans;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(target+1,vector<int>(51,-1)));
        int ans=solve(types,0,target,0,dp);
        return ans;
    }
};