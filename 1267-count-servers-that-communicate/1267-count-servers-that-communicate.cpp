class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
            if(count>=2) col[i]=1;
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==1){
                    count++;
                }
            }
            if(count>=2) row[i]=1;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (col[i] || row[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};