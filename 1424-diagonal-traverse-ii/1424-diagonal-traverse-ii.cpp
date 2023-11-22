class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> map;
        int diagonals=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                map[i+j].push_back(nums[i][j]);
                diagonals=max(diagonals,i+j);
            }
        }
        vector<int> output;
        for(int i=0;i<=diagonals;i++){
            vector<int> temp=map[i];
            reverse(temp.begin(),temp.end());
            output.insert(output.end(),temp.begin(),temp.end());
        }
        return output;
    }
};