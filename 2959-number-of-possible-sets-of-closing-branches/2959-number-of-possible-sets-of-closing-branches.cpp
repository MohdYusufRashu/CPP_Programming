class Solution {
public:
    
    bool shortestPaths(int n,vector<vector<int>> graph,int mask,int maxDistance){
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(!((mask & 1<<k) && (mask & 1<<i) && (mask & 1<<j))) continue;
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][j]>graph[i][k] + graph[k][j]){
                        graph[i][j]=graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!((mask & 1<<i) && (mask & 1<<j))) continue;
                if(graph[i][j]>maxDistance) return false;
            }
        }
        return true;
    }
    
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
        for(auto it : roads){
            graph[it[0]][it[1]]=min(graph[it[0]][it[1]],it[2]);
            graph[it[1]][it[0]]=min(graph[it[1]][it[0]],it[2]);
        }
        for(int i=0;i<n;i++){
            graph[i][i]=0;
        }
        int ans=1;
        int mask=(1<<n)-1;
        int submask=mask;
        while(submask>0){
            if(shortestPaths(n,graph,submask,maxDistance)) ans++;
            submask=(submask-1) & mask;
        }
        return ans;
    }
};