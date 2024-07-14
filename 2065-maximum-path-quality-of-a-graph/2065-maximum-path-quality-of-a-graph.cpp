class Solution {
public:
    void dfs(vector<int>& values,vector<vector<pair<int,int>>>& graph,int maxTime,int node,vector<int>& visited,int& ans,int curr){
        visited[node]++;
        if(visited[node]==1) curr+=values[node];
        if(node==0) ans=max(ans,curr);
        for(auto it : graph[node]){
            if(it.second<=maxTime){
                dfs(values,graph,maxTime-it.second,it.first,visited,ans,curr);
            }
        }
        visited[node]--;
    }
    
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> visited(n,0);
        int ans=0;
        dfs(values,graph,maxTime,0,visited,ans,0);
        return ans;
    }
};