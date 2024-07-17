class Solution {
public:
    
    void djistra(vector<vector<pair<int,int>>>& G,int src,vector<long long>& dist){
        int n=G.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            long long wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(wt>dist[node]) continue;    
            for(auto it : G[node]){
                if(dist[it.first]>dist[node] + it.second){
                    dist[it.first]=dist[node] + it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> G(n),R(n);
        for(auto edge : edges){
            G[edge[0]].push_back({edge[1],edge[2]});
            R[edge[1]].push_back({edge[0],edge[2]}); 
        }
        vector<long long> s1(n,LLONG_MAX);
        djistra(G,src1,s1);
        vector<long long> s2(n,LLONG_MAX);
        djistra(G,src2,s2);
        vector<long long> dt(n,LLONG_MAX);
        djistra(R,dest,dt);
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(s1[i]==LLONG_MAX || s2[i]==LLONG_MAX || dt[i]==LLONG_MAX) continue;
            ans=min(ans,s1[i] + s2[i] + dt[i]);
        }
        if(ans==LLONG_MAX) ans=-1;
        return ans;
    }
};