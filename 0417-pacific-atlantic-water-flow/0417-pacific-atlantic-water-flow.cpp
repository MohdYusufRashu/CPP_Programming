class Solution {
public:
    
   int n, m;
    
    int dx[4]={0, 0, 1, -1};
    int dy[4]={1, -1, 0, 0};
    
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& heights){
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m && vis[tx][ty]==0 && heights[tx][ty]<=heights[x][y])
                dfs(tx, ty, vis, heights);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> temp(2);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis.assign(n, vector<int>(m, 0));
                dfs(i, j, vis, heights);
                int p=0, a=0;
                for(int i=0; i<n; i++){
                    if(vis[i][0]==1){
                        p=1;
                    }
                    if(vis[i][m-1]==1)
                        a=1;
                }
                for(int i=0; i<m; i++){
                    if(vis[0][i]==1){
                        p=1;
                    }
                    if(vis[n-1][i]==1)
                        a=1;
                }
                if(p==1 && a==1){
                    temp[0]=i;
                    temp[1]=j;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};