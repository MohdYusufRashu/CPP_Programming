class Solution {
public:
    
    
    void solve(string& num, long long target,string temp,int index,vector<string>& ans,long long res,long long prev){
        if(index==num.size()){
            if(target==res) ans.push_back(temp);
            return;
        }
        for(int i=index;i<num.size();i++){
            if(i>index && num[index]=='0') break;
            string currString=num.substr(index,i-index+1);
            long long currNum = stoll(currString);
            if(index==0){
                solve(num,target,temp+currString,i+1,ans,currNum,currNum);
            }else{
                
                solve(num,target,temp + "+" + currString,i+1,ans,res+currNum,currNum);
                solve(num,target,temp + "-" + currString,i+1,ans,res-currNum,-currNum);
                solve(num,target,temp + "*" + currString,i+1,ans,res-prev + prev*currNum,prev*currNum);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp;
        solve(num,target,temp,0,ans,0,0);
        return ans;
    }
};