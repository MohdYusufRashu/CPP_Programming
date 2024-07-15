class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();
        int total=sz;
        int time=0;
        priority_queue<pair<int,char>> pq;
        //queue<char> q;
        unordered_map<char,int> map;
        for(int i=0;i<sz;i++){
            map[tasks[i]]++;
        }
        for(auto it : map){
            pq.push({it.second,it.first});
        }
        unordered_map<char,int> cool;
        while(total){
            time++;
            if(!pq.empty()){
                char c=pq.top().second;
                //cout<<time<<" "<<c<<endl;
                pq.pop();
                total--;
                map[c]--;
                if(map[c]>0){
                    cool[c]=n+1;
                }
            }
            for(int i=0;i<26;i++){
                char c='A' + i;
                if(cool.find(c)!=cool.end()){
                    cool[c]--;
                    if(cool[c]==0){
                        cool.erase(c);
                        pq.push({map[c],c});
                    } 
                }
                
            }
        }
        return time;
        
    }
};