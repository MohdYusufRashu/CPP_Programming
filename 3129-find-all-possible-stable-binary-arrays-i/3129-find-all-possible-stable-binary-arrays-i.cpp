int mod=1e9+7;
vector<vector<vector<vector<int>>>> dp;
class Solution {
public:
    
    int helper(int zero, int one, int count,int last,int limit){
        if(zero==0 && one==0){
            return 1;
        }
        if(last!=2 && dp[zero][one][last][count]!=-1) return dp[zero][one][last][count];
        long long ans=0;
        if(one>0){
            if(last==1 && count<limit){
                ans=helper(zero,one-1,count+1,1,limit)%mod;
            }else if(last==0 || last==2){
                ans=helper(zero,one-1,1,1,limit)%mod;
            }
        }
        if(zero>0){
            if(last==0 && count<limit){
                ans=(ans+helper(zero-1,one,count+1,0,limit))%mod;
            }else if(last==1 || last==2){
                ans=(ans+helper(zero-1,one,1,0,limit))%mod;
            }
        }
        if(last==2) return ans;
        return dp[zero][one][last][count]=ans%mod; 
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        dp=vector<vector<vector<vector<int>>>>(zero+1,vector<vector<vector<int>>>(one+1,vector<vector<int>>(2,vector<int>(limit+1,-1))));
        long long ans=helper(zero,one,0,2,limit);
        return (int)ans;
    }
};