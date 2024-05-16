class Solution {
public:
    
    int longestCommonSubsequence1(string& text1,int i, string& text2,int j,vector<vector<int>>& dp){
        if(i==text1.size() || j==text2.size()){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1+longestCommonSubsequence1(text1,i+1,text2,j+1,dp);
        }
        return dp[i][j]=max(longestCommonSubsequence1(text1,i+1,text2,j,dp),longestCommonSubsequence1(text1,i,text2,j+1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        int ans=longestCommonSubsequence1(text1,0,text2,0,dp);
        return ans;
    }
};