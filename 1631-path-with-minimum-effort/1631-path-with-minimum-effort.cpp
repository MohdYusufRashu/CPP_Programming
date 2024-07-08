#define pair pair<int,pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        priority_queue<pair,vector<pair>,greater<pair>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}}); 
        dist[0][0]=0;
        while(!pq.empty()){
            pair f=pq.top();
            pq.pop();
            int e=f.first;
            int x=f.second.first;
            int y=f.second.second;
            int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0;i<4;i++){
                int a=x+dir[i][0];
                int b=y+dir[i][1];
                if(a>=0 && a<m && b>=0 && b<n){
                    if(max(e,abs(heights[a][b]-heights[x][y])) < dist[a][b]){
                        dist[a][b]=max(abs(heights[a][b]-heights[x][y]),e);
                        pq.push({dist[a][b],{a,b}});
                    }
                    
                }
            }
        }
        return dist[m-1][n-1];
        
    }
};