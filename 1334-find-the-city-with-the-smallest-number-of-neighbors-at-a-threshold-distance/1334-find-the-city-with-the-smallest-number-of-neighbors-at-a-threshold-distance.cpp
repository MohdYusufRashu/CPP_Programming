class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
        for(auto it : edges){
            graph[it[0]][it[1]]=it[2];
            graph[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            graph[i][i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
        //vector<vector<int>> mat(n,vecotr,int>(n,0));
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][j]>graph[i][k] + graph[k][j]){
                        graph[i][j]=graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
        int temp=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(graph[i][j]<=distanceThreshold) count++;
            }
            if(count<=temp){
                temp=count;
                ans=i;
            } 
        }
        return ans;
    }
};