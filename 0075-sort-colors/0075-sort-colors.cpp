class Solution {
public:
    void sortColors(vector<int>& nums) {
       // 00011101210211002222
         // l   m        h
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                m++;
                l++;
            }else if(nums[m]==1){
                m++;
            }else{
                swap(nums[h],nums[m]);
                h--;
            }
        }
    }
};