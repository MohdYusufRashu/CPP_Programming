class Solution {
public:
    
    void solve(int n,int open,int close,vector<string>& ans,string& temp){
        if(open==n && close==n){
            ans.push_back(temp);
            return ;  
        }
        if(open<n){
            temp.push_back('(');
            solve(n,open+1,close,ans,temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            solve(n,open,close+1,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string> ans;
        string temp;
        solve(n,open,close,ans,temp);
        return ans;
    }
};