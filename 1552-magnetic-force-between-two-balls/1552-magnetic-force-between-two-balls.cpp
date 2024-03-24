class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int mi=*min_element(position.begin(),position.end());
        int ma=*max_element(position.begin(),position.end());
        int high=ma-mi;
        //cout<<high;
        int low=1;
        while(low<=high){
            int count=m;
            int mid=(low+high)>>1;
            //cout<<low<<" "<<high<<endl;
            int last=-1e9;
            for(int i=0;i<position.size();i++){
                if(position[i]-last>=mid){
                    count--;
                    last=position[i];
                    if(count==0) break;
                }
            }
            if(count==0){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};