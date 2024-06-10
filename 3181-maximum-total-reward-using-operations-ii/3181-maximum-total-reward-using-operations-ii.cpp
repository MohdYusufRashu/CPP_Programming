#define r rewardValues
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n=r.size();
        sort(r.begin(),r.end());
        bitset<50000> dp,mask;
        dp[0]=1;
        int maskIndex=0;
        for(int i=0;i<n-1;i++){
            while(maskIndex<r[i]) mask[maskIndex++]=1;
            dp=((dp&mask)<<r[i]) | dp;
        }
        int ans;
        int l=r[n-1]-1;;
        while(l>=0){
            if(dp[l]){
                ans=l;
                break;
            }
            l--;
        }
        return ans+r[n-1];
    }
};