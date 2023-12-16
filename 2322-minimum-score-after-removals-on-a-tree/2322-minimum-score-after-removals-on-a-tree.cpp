class Solution {
public:
    vector<bool> visited;
    vector<int> XOR;
    vector<vector<bool>> ancestors;
    vector<int> parent;
    vector<int> ancestor;
    vector<int> nums;
    vector<vector<int>> adj;
    
    int dfs(int v,int p){
        visited[v]=true;
        ancestor.push_back(v);
        parent[v]=p;
        int temp=nums[v];
        for(int i=0;i<adj[v].size();i++){
            int val=0;
            if(!visited[adj[v][i]]){
                val=dfs(adj[v][i],v);
            }
            temp=temp^val;
        }
        for(int i : ancestor){
            ancestors[i][v]=true;
        }
        XOR[v]=temp;
        ancestor.pop_back();
        return temp;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        visited=vector<bool>(n,false);
        XOR=vector<int>(n,0);
        ancestors=vector<vector<bool>>(n,vector<bool>(n,false));
        parent=vector<int>(n);
        ancestor=vector<int>();
        this->nums=nums;
        adj=vector<vector<int>>(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            int xor1=0,xor2=0,xor3=0;
            int p=edges[i][0],c=edges[i][1];
            if(parent[edges[i][0]]==edges[i][1]){
                p=edges[i][1];
                c=edges[i][0];
            }
            xor1=XOR[0] ^ XOR[c];
            xor2=XOR[c];
            int r1=p;
            int r2=c;
            for(int j=i+1;j<n-1;j++){
                int tempxor1=xor1;
                int tempxor2=xor2;
                p=edges[j][0];
                c=edges[j][1];
                if(parent[edges[j][0]]==edges[j][1]){
                    p=edges[j][1];
                    c=edges[j][0];
                }
                //cout<<p<<" "<<c<<" ";
                if(ancestors[c][r1]){
                    xor3=XOR[c]^xor2;
                }else{
                    xor3=XOR[c];
                }
                
                if(ancestors[r2][p]){  
                    tempxor2=xor2^XOR[c];
                }else{
                    tempxor1=xor1^xor3;
                }
                int minxor=min(tempxor1,min(tempxor2,xor3));
                int maxxor=max(tempxor1,max(tempxor2,xor3));
                ans=min(ans,maxxor-minxor);
                //cout<<ans<<endl;
            }
        }
        return ans;
    }
};