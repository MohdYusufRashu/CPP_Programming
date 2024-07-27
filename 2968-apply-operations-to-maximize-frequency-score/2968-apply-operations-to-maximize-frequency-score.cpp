class Solution {
public:
    
    bool possible(vector<int>& nums, long long k,int sz,vector<long long>& prefix){
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+sz-1;
            if(j>=n) break;
            int mid=(i+j)/2;
            //cout<<nums[mid]<<" ";
            long long median=nums[mid];
            long long cost=prefix[j]-prefix[mid]-(j-mid)*median + (mid-i)*median;
            if(mid-1>=0) cost-=prefix[mid-1];
            if(i>0) cost+=prefix[i-1];
            //cout<<cost<<endl;
            if(cost<=k){
                return true;
            }
            
        }
        return false;
        
    }
    
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        int ans=1;
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int l=2,h=n;
        while(l<=h){
            int mid=(l+h)>>1; 
            if(possible(nums,k,mid,prefix)){
                ans=max(ans,mid);
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};