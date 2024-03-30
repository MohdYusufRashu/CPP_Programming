class Solution {
public:
    
    int subarraysWithAtmostK(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int> map;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            map[nums[j]]++;
            while(map.size()>k){
                if(--map[nums[i]]==0){
                    map.erase(nums[i]);
                };
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostK(nums,k)-subarraysWithAtmostK(nums,k-1);
    }
};