class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n+4);
        rank.resize(n+4,0);
        for(int i=0;i<n+4;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findParent(int node){
        if(parent[node]==node) return node;
        return findParent(parent[node]);
    }
    
    void _union(int v1,int v2){
        int p1=findParent(v1);
        int p2=findParent(v2);
        if(p1!=p2){
            if(rank[p1]<rank[p2]){
                parent[p1]=p2;
            }else if(rank[p1]>rank[p2]){
                parent[p2]=p1;
            }else{
                parent[p1]=p2;
                rank[p2]++;
            }
        }
    }
    
};
class Solution {
public:
    
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        DSU ds(n);
        for(int i=0;i<n;i++){
            int x=circles[i][0];
            int y=circles[i][1];
            int r=circles[i][2];
            if(x>=X+r || y>=Y+r) continue;
            if (((x > (X + Y) || y > Y) && (x > X || y > X + Y))) continue;
            if(r>=x) ds._union(i,n);
            if(r>=y) ds._union(i,n+1);
            if(r>=X-x) ds._union(i,n+2);
            if(r>=Y-y) ds._union(i,n+3);
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1=circles[j][0];
                int y1=circles[j][1];
                int r1=circles[j][2];
                if(1LL*(x-x1)*(x-x1) + 1LL*(y-y1)*(y-y1)<=1LL*(r+r1)*(r+r1)) ds._union(i,j);
            }
        }
        if(ds.findParent(n) == ds.findParent(n+2) || ds.findParent(n+1) == ds.findParent(n+3)) return false;
        if(ds.findParent(n) == ds.findParent(n+1) || ds.findParent(n+3) == ds.findParent(n+2)) return false;
        return true;
    }
};