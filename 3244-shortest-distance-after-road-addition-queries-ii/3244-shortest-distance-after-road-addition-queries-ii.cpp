class Solution {
public:
    
    void eraseNodes(set<int>& s,int l,int h){
        auto lb=s.lower_bound(l);
        auto ub=s.upper_bound(h);
        s.erase(lb,ub);
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        vector<int> ans;
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(auto& q : queries){
            eraseNodes(s,q[0]+1,q[1]-1);
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};