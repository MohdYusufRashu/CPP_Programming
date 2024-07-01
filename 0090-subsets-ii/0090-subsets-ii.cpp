class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums,int index,vector<int> temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        int next=index+1;
        while(next<nums.size() && nums[next]==nums[index]){
            next++;
        }
        helper(nums,next,temp);
        for(int i=index;i<next;i++){
            temp.push_back(nums[i]);
            helper(nums,next,temp);
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans=vector<vector<int>>();
        vector<int> temp;
        helper(nums,0,temp);
        return ans;
    }
};