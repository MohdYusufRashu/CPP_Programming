class Solution {
public:
    
    void helper(vector<int>& candidates, int target,int index,vector<vector<int>>& output,vector<int> temp){
        if(target==0){
            output.push_back(temp);
            return;
        }
        if(index==candidates.size() || target<0){
            return ;
        }
        temp.push_back(candidates[index]);
        helper(candidates,target-candidates[index],index,output,temp);
        temp.pop_back();
        helper(candidates,target,index+1,output,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        helper(candidates,target,0,output,temp);
        return output;
    }
};