class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        long long ans=0;
        int maxVal=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> map;
        while(j<n){
            map[nums[j]]++;
            while(map[maxVal]==k){
                ans+=n-j;
                map[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};