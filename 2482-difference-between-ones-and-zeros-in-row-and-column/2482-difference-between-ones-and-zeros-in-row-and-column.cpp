class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int,int>> rows(m),cols(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rows[i].first++;
                    cols[j].first++;
                }else{
                    rows[i].second++;
                    cols[j].second++;
                }
            }
        }
        vector<vector<int>> diff(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=rows[i].first + cols[j].first - rows[i].second - cols[j].second;
            }
        }
        return diff;
    }
};