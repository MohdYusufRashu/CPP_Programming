class Solution {
public:
    
    vector<bool> visited;
    //unordered_map<int,pair<int,int>> m;
    pair<int,int> dfs(vector<vector<int>>& graph,int node){
        //cout<<"called node : "<<node<<endl;
        visited[node]=true;
        int dia=INT_MIN;
        int fh=INT_MIN;
        int sh=INT_MIN;
        for(int i : graph[node]){
            if(!visited[i]){
                pair<int,int> temp=dfs(graph,i);
                dia=max(dia,temp.second);
                if(temp.first>fh){
                    if(fh==INT_MIN){
                        sh=0;
                    }else{
                        sh=fh;
                    }
                    fh=temp.first;
                }else{
                    sh=max(sh,temp.first);
                }
                
            }
        }
        
        pair<int,int> ans={0,0};
        if(fh!=INT_MIN){
            ans.first=fh+1;
            ans.second=max(dia,fh+sh);
        }else {
            ans.first=1;
        }
        //cout<<"fh and sh "<<fh<<" "<<sh<<endl;
        //cout<<"node returning : "<<node<<" "<<ans.first<<" "<<ans.second<<endl;
        
        //m[node]=ans;
        return ans;
    }
    
    pair<int,int> helper(vector<vector<int>>& edges){
        int n=edges.size() + 1;
        vector<vector<int>> graph(n);
        for(auto v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        visited=vector<bool>(n);
        pair<int,int> ans=dfs(graph,0);
        return ans;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        pair<int,int> t1=helper(edges1);
        pair<int,int> t2=helper(edges2);
        cout<<t1.second<<" "<<t2.second;
        int d1=t1.second;
        int d2=t2.second;
        int connecting=((d1+1)/2) + ((d2+1)/2) +1;
        int ans=max({d1,d2,connecting});
        return ans;
    }
};