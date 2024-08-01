class Solution {
public:
    
    int mod=1e9+7;
    
    long long solve(string& num,int currSum,int index,bool prev,vector<vector<vector<int>>>& dp,int mi,int mx){
        if(currSum>mx) return 0;
        if(index==num.size()){
            if(currSum>=mi && currSum<=mx) return 1;
            return 0;
        }
        if(dp[index][currSum][prev]!=-1) return dp[index][currSum][prev];
        long long total=0;
        int x=num[index]-'0';
        if(!prev){
            for(int i=0;i<=9;i++){
                total+=solve(num,currSum+i,index+1,false,dp,mi,mx);
                total%=mod;
            }
        }else{
            for(int i=0;i<=x;i++){
                if(i==x) total+=solve(num,currSum+i,index+1,true,dp,mi,mx);
                else total+=solve(num,currSum+i,index+1,false,dp,mi,mx);
                total%=mod;
            }
        }
        total=total%mod;
        return dp[index][currSum][prev]=total;
    }
    
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        long long ans1=0,ans2=0;
        //for(int i=min_sum;i<=max_sum;i++){
            vector<vector<vector<int>>> dp1(num1.size(),vector<vector<int>>(max_sum+1,vector<int>(2,-1)));
            ans1+=solve(num1,0,0,1,dp1,min_sum,max_sum);
            ans1%=mod;
            vector<vector<vector<int>>> dp2(num2.size(),vector<vector<int>>(max_sum+1,vector<int>(2,-1)));
            ans2+=solve(num2,0,0,1,dp2,min_sum,max_sum);
            ans2%=mod;
        //}
        int temp=0;
        for(char c : num1){
            temp+=c-'0';
        }
        if(temp>=min_sum && temp<=max_sum) ans1--;
        
        return (ans2-ans1+mod)%mod;
    }
};