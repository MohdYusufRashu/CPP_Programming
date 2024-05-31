#define pb push_back
class Solution {
public:
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n =nums.size();
        int low=0;
        int high=1e6;
        long long ans=LONG_LONG_MAX;
        while(low<high){
            int mid=(low+high)>>1;
            long long l=0,m=0,r=0;
            for(int i=0;i<n;i++){
                l+=abs(nums[i]-mid+1)*1LL*cost[i];
                m+=abs(nums[i]-mid)*1LL*cost[i];
                r+=abs(nums[i]-mid-1)*1LL*cost[i];
            }
           // ans=*min_element({ans,l,m,r}.begin(),{ans,l,m,r}.end());
            //ans=min(ans,min(l,min(r,m)));
            ans=min({ans,l,m,r});
            if(l>m && r>m) break;
            else if(l>m) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};