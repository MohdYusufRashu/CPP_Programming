#define pb push_back

class Solution {
public:
    
    void helper(int index,vector<int>& nums,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.pb(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            helper(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};