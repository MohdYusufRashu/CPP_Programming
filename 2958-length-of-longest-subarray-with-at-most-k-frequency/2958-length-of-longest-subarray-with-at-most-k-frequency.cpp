class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        int ans=INT_MIN;
        int i=0,j=0;
        while(j<n){
            map[nums[j]]++;
            if(map[nums[j]]>k){
                while(nums[i]!=nums[j]){
                    map[nums[i]]--;
                    i++;
                }
                map[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};