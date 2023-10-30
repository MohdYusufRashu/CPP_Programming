class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int zeros=0;
                int ones=0;
                int mat[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
                for(int k=0;k<8;k++){
                    int x=i+mat[k][0];
                    int y=j+mat[k][1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(board[x][y]==0 || board[x][y]==3){
                            zeros++;
                        }else{
                            ones++;
                        }
                    }
                }
                if(board[i][j]==0){
                    if(ones==3) board[i][j]=3;
                }else{
                    if(ones<2) board[i][j]=2;
                    else if(ones>3) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=0;
                if(board[i][j]==3) board[i][j]=1;
            }
        }
    }
};