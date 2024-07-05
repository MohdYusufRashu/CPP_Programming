class Solution {
public:
    vector<vector<bool>> visited;
    bool dfs(vector<vector<int>>& grid,int x,int y,int& ans,int m,int n){
        ans++;
        visited[x][y]=true;
        bool safe=true;
        if(x==0 || x==m-1 || y==0 || y==n-1) safe=false;
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<4;i++){
            int a=x+dir[i][0];
            int b=y+dir[i][1];
            if(a>=0 && a<m && b>=0 && b<n && !visited[a][b] && grid[a][b]==1){
                if(!dfs(grid,a,b,ans,m,n)) safe=false;
            }
        }
        return safe;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int total=0;
        visited=vector<vector<bool>>(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ans=0;
                if(!visited[i][j] && grid[i][j]==1){
                    if(dfs(grid,i,j,ans,m,n)) total+=ans;
                }
            }
        }
        return total;
    }
};