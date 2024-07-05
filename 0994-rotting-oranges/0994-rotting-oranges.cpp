class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
            int x=q.front().first.first;
            int y=q.front().first.second;
            int minutes=q.front().second;
            ans=max(ans,minutes);
            q.pop();
            for(int i=0;i<4;i++){
                int a=x+dir[i][0];
                int b=y+dir[i][1];
                if(a>=0 && a<m && b>=0 && b<n && !visited[a][b] && grid[a][b]==1){
                    grid[a][b]=2;
                    q.push({{a,b},minutes+1});
                    visited[a][b]=true;
                }
            } 
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans=max(ans,0);
    }
};