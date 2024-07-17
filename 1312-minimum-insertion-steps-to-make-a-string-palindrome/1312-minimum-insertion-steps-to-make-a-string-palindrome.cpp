class Solution {
public:
    
    int solve(string& s,int i,int j,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        //cout<<i<<" "<<j<<endl;
        if(s[i]==s[j]){
            ans+=solve(s,i+1,j-1,dp);
        }else{
            ans+=min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
            ans++;
        }
        return dp[i][j]=ans;
    }
    
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        int ans=solve(s,0,n-1,dp);
        return ans;
    }
};