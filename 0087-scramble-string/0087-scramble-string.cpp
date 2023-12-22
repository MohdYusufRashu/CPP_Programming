class Solution {
public:
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
        } 
        string x,y;
        for(int i=0;i<s1.size()-1;i++){
            x=s1.substr(0,i+1);
            y=s1.substr(i+1);
            int xl=x.size();
            int yl=y.size();
            if((helper(x,s2.substr(0,xl)) && helper(y,s2.substr(xl))) || (helper(y,s2.substr(0,yl)) && helper(x,s2.substr(yl,xl)))){
                dp[temp]=true;
                return true;
            }
        }
        dp[temp]=false;
        return false;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        return helper(s1,s2);
    }
};