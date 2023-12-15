class Solution {
public:
    
    int helper(vector<pair<int,int>>& temp,int index,int last,vector<vector<int>>& dp){
        if(index==temp.size()){
            return 0;
        }
        if(dp[index][last]!=-1) return dp[index][last];
        int ans=helper(temp,index+1,last,dp);
        if(last==0){
            ans=max(ans,temp[index].second + helper(temp,index+1,index+1,dp));
        }
        else if((temp[index].second)>=temp[last-1].second){
            ans=max(ans,temp[index].second + helper(temp,index+1,index+1,dp));
        }
        dp[index][last]=ans;
        return ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> temp(n);
        for(int i=0;i<n;i++){
            temp[i].first=ages[i];
            temp[i].second=scores[i];
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=helper(temp,0,0,dp);
        return ans;
    }
};