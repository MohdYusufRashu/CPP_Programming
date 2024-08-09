class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m/2;i++){
            int j=0,k=n-1;
            while(j<k){
                if(j==k){
                    continue;
                }
                else if(grid[i][j]==grid[i][k]){
                        if(grid[m-1-i][j]!=grid[i][j]){
                            grid[m-1-i][j]=grid[i][j];
                            //cout<<i<<" "<<j<<endl;
                            count++;
                        }
                        if(grid[m-1-i][k]!=grid[i][k]){
                            grid[m-1-i][k]=grid[i][k];
                            //cout<<i<<" "<<j<<endl;
                            count++;
                        }  
                }else{
                    if(grid[m-1-i][j]==grid[m-1-i][k]){ 
                        count++;
                    }else{
                        count+=2;
                    }
                    grid[i][j]=grid[i][k]=grid[m-1-i][j]=grid[m-1-i][k]=0;
                }
                cout<<count<<endl;
                j++;
                k--;
            }
        }
        if(m%2==0 && n%2==0) return count;
        int pairs=0;
        int diff=0;
        if(n%2==1){
            for(int i=0;i<m/2;i++){
                if(grid[i][n/2]==1 && grid[m-i-1][n/2]==1) pairs++;
                if(grid[i][n/2]!= grid[m-i-1][n/2]){
                    count++;
                    diff++;
                }
            }
        }
        if(m%2==1){
            for(int i=0;i<n/2;i++){
                if(grid[m/2][i]==1 && grid[m/2][n-i-1]==1) pairs++;
                if(grid[m/2][i]!= grid[m/2][n-i-1]){
                    count++;
                    diff++;
                }
            }
        }
        if(pairs%2==1){
            if(diff==0) count+=2;
        }
        if(n%2==1 && m%2==1 && grid[m/2][n/2]==1) count++;
        return count;
    }
};