class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //bool ans;
        map<int,int> map;
        for(int i=0;i<hand.size();i++){
            map[hand[i]]++;
        }
        int count=groupSize;
        /*for(auto it : map){
            cout<<it.first<< " " <<it.second <<endl;;
        }*/
        while(map.size()){
            count=groupSize;
            int last;
            for(auto it : map){
                if(map.size()==0){
                    return false;
                }
                if(count==groupSize){
                    count--;
                    last=it.first;
                    cout<<last<<" "<<it.second<<endl;
                    it.second--;
                    map[last]=it.second;
                    cout<<it.second<<endl;
                    if(it.second==0){
                        map.erase(it.first);
                    }
                }else{
                    if(last+1!=it.first){
                        return false;
                    }
                    (it.second)--;
                    last=it.first;
                    map[last]=it.second;
                    if(it.second==0){
                        map.erase(it.first);
                    }
                    cout<<last<<" "<<it.second<<endl;
                    cout<<it.second<<endl;
                    count--;
                }
                if(count==0){
                    cout<<"break";
                    break;
                } 
            }
            
        }
        if(count) return false;
        return true;
        
    }
};