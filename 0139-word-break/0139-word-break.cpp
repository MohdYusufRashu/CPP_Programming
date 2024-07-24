class Solution {
public:
    vector<int> dp;
    
    bool solve(string s, vector<string>& wordDict,unordered_set<string>& dict,int index){
        if(index==s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<s.size();i++){
            string word=s.substr(index,i-index+1);
            if(dict.find(word)!=dict.end()){
                if(solve(s,wordDict,dict,i+1)) return dp[index]=1;
            }
        }
        return dp[index]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        dp=vector<int>(n,-1);
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return solve(s,wordDict,dict,0);
        /*int i=0,j=0;
        while(j<n){
            string word=s.substr(i,j-i+1);
            if(j==n-1){
                if(dict.find(word)==dict.end()) return false;
            }
            if(dict.find(word)!=dict.end()) i=j+1; 
            j++;
        }
        return true;*/
    }
};