class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> weights(n,INT_MAX);
        weights[src]=0;
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        for(int x=0;x<=k;x++){
            vector<int> temp=weights;
            for(int i=0;i<n;i++){
                int v1=i;
                for(int j=0;j<graph[v1].size();j++){
                    int v2=graph[i][j].first;
                    int cost=graph[i][j].second;
                    if(temp[v1]!=INT_MAX && weights[v2]>temp[v1]+cost){
                        weights[v2]=temp[v1]+cost;
                    }
                }
            }
        }
        if(weights[dst]==INT_MAX) return -1;
        return weights[dst];
    }
};