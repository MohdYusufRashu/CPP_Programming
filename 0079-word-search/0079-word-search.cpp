class Solution {
public:
    
    bool helper(vector<vector<char>>& board, string word,int x,int y,int index,vector<vector<bool>>& visited){
        //cout<<x<<" "<<y<<"  :  "<<index<<endl;
        if(board[x][y]!=word[index]) return false;
        if(index==word.size()-1) return true;
        visited[x][y]=true;
        int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<4;i++){
            int a=x+dir[i][0];
            int b=y+dir[i][1];
            if(a>=0 && a<(board.size()) && b>=0 && b<(board[0].size()) && !visited[a][b]){
                if(helper(board,word,a,b,index+1,visited)){
                    return true;
                }
            }
        }
        visited[x][y]=false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(helper(board,word,i,j,0,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};