class Solution {
public:
    //vector<vector<vector<string>>> dp;
    unordered_map<string,bool> dp;
    bool helper(string s1,string s2){
        string temp=s1 + "#" + s2;
        if(dp.find(temp)!=dp.end()){
            return dp[temp];
        }
        
        
        if(s1==s2){
            dp[temp]=true;
            return true;
        }    
        if(s1.size()==1){
            dp[temp]=false;
            return false;
        } ;
        string x,y;
        bool ans=false;
        for(int i=0;i<s1.size()-1;i++){
            x=s1.substr(0,i+1);
            y=s1.substr(i+1);
            int xl=x.size();
            int yl=y.size();
            bool temp=false;
            temp=temp || (helper(x,s2.substr(0,xl)) && helper(y,s2.substr(xl)));
            temp = temp || (helper(y,s2.substr(0,yl)) && helper(x,s2.substr(yl,xl)));
            ans=ans || temp; 
            if(ans) break;
        }
        dp[temp]=ans;
        return ans;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
       // dp=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return helper(s1,s2);
    }
};