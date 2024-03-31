class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int minIndex=-1,maxIndex=-1;
        int violation=-1;
        int i=0,j=0;
        long long ans=0;
        while(j<n){
            if(nums[j]==minK){
                minIndex=j;
            }
            if(nums[j]==maxK){
                maxIndex=j;
            }
            if(nums[j]<minK || nums[j]>maxK){
                minIndex=-1;
                maxIndex=-1;
                violation=j;
            }
            if(minIndex>=0 && maxIndex>=0){
                ans+=min(minIndex,maxIndex)-(violation+1)+1;
            }
            j++;
        }
        return ans;
    }
};