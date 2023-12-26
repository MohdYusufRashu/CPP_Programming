class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        //set<string> s;
        int n=creators.size();
        unordered_map<string,int> idtoindex;
        for(int i=0;i<n;i++){
            idtoindex[ids[i]]=i;
        }
        //cout<<"g index : "<<idtoindex["g"]<<endl;
        unordered_map<string,pair<long long,int>> map;
        long long maxviews=0;
        for(int i=0;i<n;i++){
            if(map.find(creators[i])!=map.end()){
                //string id=map[creators[i]].second;
                //int index=idtoindex[id];
                int index=map[creators[i]].second;
                pair<long long,int> p;
                long long sum=map[creators[i]].first + views[i];
                //maxviews=max(maxviews,sum);
                /*if(creators[i]=="d"){
                    cout<<id<<" "<<index<<" "<<views[index]<<" : "<<ids[i]<<" "<<i<<" "<<views[i]<<endl;
                }*/
                if(views[index]<views[i]){
                    p={sum,i};
                }else if(views[index]==views[i]){
                    if(ids[index]<ids[i]){
                        p={sum,index};
                    }else{
                        p={sum,i};
                    }
                }else{
                    p={sum,index};
                }
                map[creators[i]]=p;
            }else{
                map[creators[i]]={views[i],i};
                if(creators[i]=="d"){
                    cout<<ids[i]<<" "<<views[i]<<endl;
                }
            }
        }
        for(auto it : map){
            if(it.second.first>maxviews){
                maxviews=it.second.first;
            }
        }
        cout<<maxviews;
        vector<vector<string>> output;
        for(auto it : map){
            if(it.second.first==maxviews){
                string creator=it.first;
                string id=ids[it.second.second];
                //cout<<it.second.first<<" ";
                output.push_back({creator,id});
            }
        }
        //cout<<endl<<map["f"].first;
        return output;
    }
};