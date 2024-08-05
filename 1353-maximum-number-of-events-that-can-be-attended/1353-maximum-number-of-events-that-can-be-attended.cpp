class Solution {
public:
    
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        int i=0;
        for(int d=1;d<=1e5;d++){
            while(!pq.empty() && pq.top()<d) pq.pop();
            while(i<n && events[i][0]==d) pq.push(events[i++][1]);
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};