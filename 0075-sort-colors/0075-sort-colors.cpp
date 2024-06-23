class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n;
        while(mid<high){
            if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else{
                swap(nums[mid],nums[high-1]);
                high--;
            }
        }
    }
};

