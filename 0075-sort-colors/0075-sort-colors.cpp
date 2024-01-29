class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size();
        while(mid<high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                high--;
                swap(nums[high],nums[mid]);
            }
        }
    }
    
     //0000011110210202012222
        //  l   m        h
};