class Solution {
public:
    
    int helper(vector<int>& nums,int index, int target,int sum){
        if(index==nums.size()){
            if(target==sum) return 1;
            return 0;
        }
        int ans=0;
        ans+=helper(nums,index+1,target,sum+nums[index]);
        ans+=helper(nums,index+1,target,sum-nums[index]);
        return ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,0,target,0);
    }
};