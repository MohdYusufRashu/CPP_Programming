class Solution {
public:
    
    class DisjointSet{
        vector<int> parent,rank,cost;
        public : 
        DisjointSet(int n){
            rank.resize(n,0);
            cost.resize(n,(1<<30)-1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionByRank(int u,int v,int weight){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv){
                cost[pu]=cost[pu] & weight;
            } 
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
                cost[pv]=cost[pv] & cost[pu] & weight;
            }else if(rank[pu]>rank[pv]){
                parent[pv]=pu;
                cost[pu]=cost[pu] & weight & cost[pv];
            }else{
                parent[pu]=pv;
                cost[pv]=cost[pv] & weight & cost[pu];
                rank[pv]++;
            }
        }
        int findCost(int node){
            return cost[findParent(node)];
        }
    };
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        DisjointSet ds(n);
        for(auto& edge : edges){
            ds.unionByRank(edge[0],edge[1],edge[2]);
        }
        for(auto& q : query){
            int pu=ds.findParent(q[0]);
            int pv=ds.findParent(q[1]);
            if(pu!=pv){
                ans.push_back(-1);
            }else{
                ans.push_back(ds.findCost(pu));
            }
        }
        return ans;
    }
};