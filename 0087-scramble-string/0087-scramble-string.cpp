class Solution {
public:
    //vector<vector<vector<string>>> dp;
    unordered_map<string,bool> dp;
    bool helper(string s1, string s2c,string& s2,int start,int end){
        string temp=s1 + "#" + s2c;
        if(dp.find(temp)!=dp.end()){
            return dp[temp];
        }
        
        
        if(s1==s2c){
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
            //cout<<x<<" "<<y<<endl;
            bool flag=false;
            bool flag2=false;
            if(s1=="abcdbdac"){
                if(x=="abcd" && y=="bdac"){
                    flag2=true;
                }
                cout<<x<<" "<<y<<endl;
                cout<<start<<" "<<end<<endl;
                flag=true;
            }
            bool temp=false;
            temp=temp || (helper(x,s2.substr(start,xl),s2,start,start + xl-1) && helper(y,s2.substr(start+xl,yl),s2,start+xl,end));
            temp = temp || (helper(y,s2.substr(start,yl),s2,start,start+yl-1) && helper(x,s2.substr(start+yl,xl),s2,start+yl,end));
            ans=ans || temp; 
            if(ans) break;
        }
        dp[temp]=ans;
        return ans;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
       // dp=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return helper(s1,s2,s2,0,s1.size()-1);
    }
};