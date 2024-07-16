class Solution {
public:
    int mod=1e9+7;
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y,vector<vector<int>>& dp){
        //cout<<x<<" "<<y<<endl;
        int m=grid.size();
        int n=grid[0].size();
        visited[x][y]=true;
        //pathvisited[x][y]=true;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        long long ans=1;
        for(int i=0;i<4;i++){
            int a=x + dir[i][0];
            int b=y+ dir[i][1];
            if(a>=0 && a<m && b>=0 && b<n && grid[a][b]>grid[x][y]){
                if(!visited[a][b]){
                   dfs(grid,visited,a,b,dp); 
                }
                if(dp[a][b]!=-1) ans=(ans+dp[a][b])%mod;
            }
            
        }
        dp[x][y]=ans;
        //cout<<x<<" "<<y<<"  : "<<ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<bool>> visited(m,vector<bool>(n));
        vector<vector<bool>> pathvisited(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    dfs(grid,visited,i,j,dp);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];
                ans=ans%mod;
            }
        }
        return (int)ans;
    }
};