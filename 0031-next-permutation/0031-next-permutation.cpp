class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){ 
            i--;
        } 
        if(i<0){
            reverse(nums.begin(),nums.end()); //O(N)
            return;
        }
        
        int val=INT_MAX;
        int index;
        for(int j=i+1;j<n;j++){       //O(N)
            if(nums[j]>nums[i] && nums[j]<=val){
                val=nums[j];
                index=j;
            }
        }
        swap(nums[i],nums[index]);
        reverse(nums.begin()+i+1,nums.end()); //O(NlogN)
        return;
    }
};