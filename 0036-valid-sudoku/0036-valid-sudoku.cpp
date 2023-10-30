class Solution {
public:
    
    bool checkLine(vector<vector<char>>& board,int x,int flag){
        int arr[10]={0};
        for(int i=0;i<9;i++){
            if(flag==0){
                if(board[x][i]=='.'){
                    continue;
                }
                if(arr[board[x][i]-48]){
                    return false;
                }
                arr[board[x][i]-48]++;
            }else{
                if(board[i][x]=='.'){
                    continue;
                }
                if(arr[board[i][x]-48]){
                    return false;
                }
                arr[board[i][x]-48]++;
            }  
        }
        return true;
    }
    bool checkBox(vector<vector<char>>& board,int x,int y){
        int arr[10]={0};
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(arr[board[i][j]-48]){
                    return false;
                }
                arr[board[i][j]-48]++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!checkLine(board,i,0)){
                return false;
            }
            if(!checkLine(board,i,1)){
                return false;
            }
        }
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                if(!checkBox(board,i,j)){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};