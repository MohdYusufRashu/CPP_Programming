class Solution {
    vector<int> nextGreaterElement(vector<int>& nums) {
       int n = nums.size();
       stack<int> st;
       vector<int> ans(n,INT_MAX);

       for(int i=n-1; i>=0; i--)
       {
           while(!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

           if(!st.empty())
            ans[i] = st.top();

           st.push(i);
       }
    return ans;
   }
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0;
       vector<int> next = nextGreaterElement(nums);
       unordered_map<int,vector<int>> m;
       for(int i=0; i<nums.size(); i++) {
           m[nums[i]].push_back(i);
       }
       
      for(int i=0; i<nums.size(); i++) {
          int x1 = lower_bound(m[nums[i]].begin(),m[nums[i]].end(),i) - m[nums[i]].begin();
          int x2 = upper_bound(m[nums[i]].begin(),m[nums[i]].end(),next[i]) - m[nums[i]].begin();
          ans += (x2-x1);
      }
    return ans;
    }
};