#define pb push_back
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size();
        unordered_map<int,pair<int,int>> map;
        vector<int> output;
        int mx=0;
        for(int i=0;i<n;i++){
            int x=positions[i][0];
            int side=positions[i][1];
            int maxHeight=0;
            int y=x+side;
            for(auto it : map){
                int a=it.first;
                int b=a+it.second.first;
                if((a>=x && a<y) || (b>x && b<=y) ||(x>=a && x<b) || (y>a && y<=b)){
                //if((x>=it.first && x<it.first + it.second.first) || (y>it.first && y<it.first + it.second.first)){
                    maxHeight=max(maxHeight,it.second.second);
                }
            }
            mx=max(mx,maxHeight+side);
            output.pb(mx);
            map[x]={side,maxHeight+side};
            cout<<x<<" "<<map[x].first<<" "<<map[x].second<<endl;
        }
        return output;
    }
};