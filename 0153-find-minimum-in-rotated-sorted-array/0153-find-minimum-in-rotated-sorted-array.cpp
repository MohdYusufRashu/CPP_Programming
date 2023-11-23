class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        while(low<high){
            int mid=(low+high)>>1;
            if(mid-1>=0 && nums[mid-1]>nums[mid] && mid+1<n && nums[mid+1]>nums[mid]){
                return nums[mid];
            }
            if(nums[high]<nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};