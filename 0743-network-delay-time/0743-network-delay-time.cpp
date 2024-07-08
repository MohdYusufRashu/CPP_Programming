class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto v : times){
            graph[v[0]-1].push_back({v[1]-1,v[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int> f=pq.top();
            int time=f.first;
            int node=f.second;
            //cout<<node<<endl;
            pq.pop();
            for(int i=0;i<graph[node].size();i++){
                int v=graph[node][i].first;
                int w=graph[node][i].second;
                if(dist[v]>time + w){
                    dist[v]=dist[node]+w;
                    //ans=max(ans,dist[v]);
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i : dist){
            if(i==INT_MAX) return -1;
            ans=max(ans,i);
        }
        return ans;
        
    }
};