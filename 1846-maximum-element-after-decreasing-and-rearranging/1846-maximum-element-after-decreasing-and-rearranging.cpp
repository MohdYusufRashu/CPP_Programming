class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        map<int,int> map;
        for(auto it :arr){
            map[it]++;
        }
        int ans=0;
        for(auto it : map){
            ans=ans+min(it.first-ans,it.second);
        }
        return ans;
    }
};