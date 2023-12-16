class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        //vector<bool> visited(n);
        //vector<bool> pathvisited;
        vector<int> output;
        //dfs(graph,numCourses,visited,pathvisited,output,0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int v=q.front();
            output.push_back(v);
            q.pop();
            for(int i=0;i<graph[v].size();i++){
                if(--indegree[graph[v][i]]==0) q.push(graph[v][i]) ;
            }
        }
        if(output.size()!=numCourses) return vector<int>();
        return output;
    }
};