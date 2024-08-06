class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events, int k,int index,vector<int>& start){
        if(k==0 || index>=events.size()) return 0;
        if(dp[index][k]!=-1) return dp[index][k];
        return dp[index][k]=max(events[index][2] + solve(events,k-1,start[index],start),solve(events,k,index+1,start));
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        dp=vector<vector<int>>(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        vector<int> start;
        for(auto v : events){
            start.push_back(v[0]);
        }
        for(int i=0;i<start.size();i++){
            int next=upper_bound(start.begin()+i+1,start.end(),events[i][1])-start.begin();
            start[i]=next;
        }
        return solve(events,k,0,start);
        
    }
};