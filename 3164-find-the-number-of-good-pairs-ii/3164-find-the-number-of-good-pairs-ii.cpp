class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        unordered_map<int,int> map;
        for(int x : nums2){
            map[x*k]++;
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=1;j<=sqrt(nums1[i]);j++){
                if(nums1[i]%j==0){
                    if(map.count(j)>0){
                        ans+=map[j];
                    }
                    if(map.count(nums1[i]/j)>0 && j!=nums1[i]/j) ans+=map[nums1[i]/j];
                }
            }
        }
        return ans;
    }
};