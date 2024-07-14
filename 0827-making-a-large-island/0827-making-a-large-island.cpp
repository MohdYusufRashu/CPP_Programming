class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& mat,int i,int j,vector<vector<bool>>& visited,int& sz,int x,vector<vector<int>>& id){
        int n=grid.size();
        sz++;
        visited[i][j]=true;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int a=i + dir[k][0];
            int b=j + dir[k][1];
            if(a>=0 && a<n && b>=0 && b<n && !visited[a][b] && grid[a][b]==1){
                dfs(grid,mat,a,b,visited,sz,x,id);
            }
        }
        //mat[i][j]=sz;
        id[i][j]=x;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> mat(n,vector<int>(n,0));
        vector<vector<int>> id(n,vector<int>(n,0));
        vector<vector<bool>> visited(n,vector<bool>(n));
        unordered_map<int,int> map;
        int x=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int sz=0;
                    dfs(grid,mat,i,j,visited,sz,x,id);
                    map[x]=sz;
                    x++;
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<mat[i][j]<<" "; 
                if(id[i][j]!=0){
                    ans=max(ans,map[id[i][j]]);
                    continue;
                }
                int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
                int temp=0;
                unordered_set<int> s;
                for(int k=0;k<4;k++){
                    int a=i + dir[k][0];
                    int b=j + dir[k][1];
                    if(a>=0 && a<n && b>=0 && b<n && id[a][b]!=0){
                        if(s.find(id[a][b])==s.end()){
                            temp+=map[id[a][b]];
                            s.insert(id[a][b]);
                        }
                        
                    }
                }
                ans=max(ans,temp+1);
            }
            //cout<<endl;
        }
        return ans;    
        
    }
};