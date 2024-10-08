class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int last=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<last){
                count++;
                if(intervals[i][1]<last){
                    last=intervals[i][1];
                }
                //cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            }else{
                last=intervals[i][1];
            }
            
        }
        return count;
    }
};