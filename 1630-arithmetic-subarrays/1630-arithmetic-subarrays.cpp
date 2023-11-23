class Solution {
public:
    
    bool isSequence(vector<int> temp){
        sort(temp.begin(),temp.end());
        int d=temp[1]-temp[0];
        for(int i=2;i<temp.size();i++){
            if(temp[i]-temp[i-1]!=d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> temp;
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            if(isSequence(temp)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};