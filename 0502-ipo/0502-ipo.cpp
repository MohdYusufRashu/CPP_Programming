class Solution {
public:
    static bool Compare(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>> pq;
        int n=v.size();
        int i=0;
        while(i<n){
            if(v[i].first<=w){
                pq.push({v[i].second,v[i].first});
                i++;
            }else{
                if(pq.empty()){
                    return w;
                }
                w+=(pq.top().first);
                pq.pop();
                k--;
                if(k==0){
                    return w;
                }
            }
            
        }
        while(!pq.empty()){
            w=w+pq.top().first;
            pq.pop();
            k--;
            if(k==0){
                return w;
            }
        }
        return w;
    }
};