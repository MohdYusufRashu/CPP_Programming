class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n+1,INT_MAX);
        vector<int> curr(n+1,INT_MAX);
        curr[n-1]=grid[m-1][n-1];
        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(row==m-1 && col==n-1) continue;
                curr[col]=grid[row][col] + min(curr[col+1],prev[col]);
         }
            prev=curr;
        }
        return curr[0];
        
    }
};