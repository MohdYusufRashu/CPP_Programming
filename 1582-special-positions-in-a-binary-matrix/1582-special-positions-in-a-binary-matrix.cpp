class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> row(m,-1);
        vector<int> col(n,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    if(row[i]==-1){
                        row[i]=j;
                    }else{
                        row[i]=-2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[j][i]==1){
                    if(col[i]==-1){
                        col[i]=j;
                    }else{
                        col[i]=-2;
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            if(row[i]!=-1 && row[i]!=-2){
                if(col[row[i]]!=-2) count++;
            }
        }
        return count;
    }
};