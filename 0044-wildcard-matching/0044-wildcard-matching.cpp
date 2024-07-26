class Solution {
public:
    
    bool solve(string& s, string& p,int i,int j,vector<vector<int>>& dp){
        if(j==p.size()){
            if(i==s.size()) return 1;
            return 0;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=0;
        if(i==s.size()){
            if(p[j]!='*') ans=0;
            else ans=solve(s,p,i,j+1,dp);
        }
        else if(s[i]==p[j] || p[j]=='?') ans=solve(s,p,i+1,j+1,dp);
        else if(p[j]=='*'){
            ans=solve(s,p,i,j+1,dp) || solve(s,p,i+1,j+1,dp) || solve(s,p,i+1,j,dp);
        }
        return dp[i][j]=ans;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size(),-1));
        return solve(s,p,0,0,dp);
    }
};