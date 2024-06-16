#define pb push_back

class Solution {
public:
    
   /* long long helper(vector<int>& power,int index,int last){
        int n=power.size();
        if(index==n) return 0;
        //if(dp[index]!=-1) return dp[index];
        long long ans=0;
        //exclude
        ans=max(ans,helper(power,index+1,last));
        //include
        if(power[index]-last>2 || power[index]==last){
            ans=max(ans,power[index] + helper(power,index+1,power[index])); 
        }
        //cout<<ans<<" ";
        return dp[index]=ans;
        return ans;
    }*/
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        sort(power.begin(),power.end());
        vector<long long> dp(power.size(),-1);
        vector<long long> mx(power.size());
        dp[0]=power[0];
        mx[0]=power[0];
        for(int i=1;i<power.size();i++){
            if(power[i]==power[i-1]){
                dp[i]=dp[i-1]+power[i];
            }else{
                int req=power[i]-3;
                int index=(upper_bound(power.begin(),power.begin()+i,req))-power.begin();
                if(index-1>=0) dp[i]=power[i] + max(mx[index-1],dp[index-1]);
                else dp[i]=power[i];
            }
            cout<<dp[i]<<" ";
            mx[i]=max(mx[i-1],dp[i]);
        }
        long long ans=0;
        for(long long i : dp){
            ans=max(ans,i);
        }
        return ans;
    }
};