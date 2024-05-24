class Solution {
public:
    
    vector<int> djisktra(int n,vector<vector<pair<int,int>>>& graph,int start){
        vector<int> weight(n,INT_MAX);
        weight[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,start});
        vector<bool> visited(n);
        while(!pq.empty()){
            int node=pq.top().second;
            int curr_weight=pq.top().first;
            pq.pop();
            if(visited[node]) continue;
            visited[node]=true;
            for(int i=0;i<graph[node].size();i++){
                if(!visited[graph[node][i].first] && curr_weight + graph[node][i].second <weight[graph[node][i].first]){
                    weight[graph[node][i].first] = curr_weight + graph[node][i].second;
                    pq.push({weight[graph[node][i].first],graph[node][i].first});
                }
            }
            
        }
        return weight;
    }
    
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int> djAtZero=djisktra(n,graph,0);
        vector<int> djAtLast=djisktra(n,graph,n-1);
        /*for(int i=0;i<n;i++){
            cout<<djAtZero[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<djAtLast[i]<<" ";
        }*/
        
        int dist=djAtZero[n-1];
        
        vector<bool> ans(edges.size());
        for(int i=0;i<edges.size();i++){
            if(dist==INT_MAX || djAtZero[edges[i][0]]==INT_MAX || djAtLast[edges[i][1]]==INT_MAX) continue;
            if((edges[i][2] + djAtZero[edges[i][0]] + djAtLast[edges[i][1]])==dist){
                ans[i]=true;
            }
            if(djAtLast[edges[i][0]]==INT_MAX || djAtZero[edges[i][1]]==INT_MAX) continue;
            if((edges[i][2] + djAtZero[edges[i][1]] + djAtLast[edges[i][0]])==dist){
                ans[i]=true;
            }
        }
        return ans;
    }
};