class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int prod=1;
        int count=0;
        while(j<n){
            prod*=nums[j];
             while(prod>=k && i<=j){
                prod/=nums[i];
                i++;
            }
            if(prod<k){

                count+=j-i+1;
            }
            j++;
        }
        return count;
    }
};