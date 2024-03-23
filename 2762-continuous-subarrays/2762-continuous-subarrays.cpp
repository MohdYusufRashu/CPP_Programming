class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        deque<int> maxQ;
        deque<int> minQ;
        int l=0,r=0;
        long long ans=0;
        while(r<n){
            
            //updating the queue
            while(!maxQ.empty() && nums[r]>maxQ.back()){
                maxQ.pop_back();
            }
            while(!minQ.empty() && nums[r]<minQ.back()){
                minQ.pop_back();
            }
            maxQ.push_back(nums[r]);
            minQ.push_back(nums[r]);
            
            //shrink if needed
            while(maxQ.front()-minQ.front()>2){
                if(maxQ.front()==nums[l]){
                    maxQ.pop_front();
                }
                if(minQ.front()==nums[l]){
                    minQ.pop_front();
                }
                l++;
            }
            
            //update answer
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};