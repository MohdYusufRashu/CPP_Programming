class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x){
            return y-x;
        }
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        q.push({x,0});
        while(!q.empty()){
            int val=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(visited.find(val)!=visited.end()) continue;
            if(val==-1){
                if(!q.empty()){
                    q.push({-1,-1});
                }
            }else{
                visited.insert(val);
                if(val==y){
                    return dist;
                }
                bool flag=false;
                //if(visited.find(val)!=visited.end()) flag=true;
                if(val>=11 && !flag && val%11==0){
                    q.push({val/11,dist+1});
                }
                if(val>=5 && !flag && val%5==0){ 
                    q.push({val/5,dist+1});
                }
                if(val>1){
                    q.push({val-1,dist+1});
                }
                if(val<x+11){
                    q.push({val+1,dist+1});
                }
                
            }
        }
        return -1;
    }
};