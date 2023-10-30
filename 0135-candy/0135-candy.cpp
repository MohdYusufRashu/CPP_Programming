class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(ratings.size(),1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(p.second-1>=0 && ratings[p.second-1]<ratings[p.second]){
                candies[p.second]=candies[p.second-1]+1;
            } 
            if(p.second+1<n && ratings[p.second+1]<ratings[p.second]){
                candies[p.second]=max(candies[p.second],candies[p.second+1]+1);
            }
        }
        int ans=accumulate(candies.begin(),candies.end(),0);
        return ans;
        
    }
};