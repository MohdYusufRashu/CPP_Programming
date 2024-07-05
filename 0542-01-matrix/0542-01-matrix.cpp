class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int a=x+dir[i][0];
                int b=y+dir[i][1];
                if(a>=0 && a<m && b>=0 && b<n && !visited[a][b] && mat[a][b]==1){
                    mat[a][b]=dist+1;
                    q.push({{a,b},dist+1});
                    visited[a][b]=true;
                }
            } 
        }
        return mat;
    }
};