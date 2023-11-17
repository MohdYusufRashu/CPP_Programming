class Solution {
public:
    static bool Compare(pair<int,int> p1,pair<int,int> p2){
        if(p1.first!=p2.first){
            return p1.first<p2.first;
        }else{
            return p1.second>p2.second;
        }
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> temp(ranges.size());
        for(int i=0;i<ranges.size();i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            temp[i]={l,r};
        }
        cout<<n;
        sort(temp.begin(),temp.end(),Compare);
        int count=1;
        if(temp[0].first!=0) return -1;
        int curr=temp[0].second;
        int i=1;
        cout<<curr;
        while(i<ranges.size() && curr!=n){
            int next=0;
            while(i<ranges.size() && temp[i].first<=curr){
                next=max(next,temp[i].second);
                i++;
            }
            if(next>curr){
                count++;
                curr=next;
            }else{
                return -1;
            }
        }
        if(curr==n) return count;
        return -1;
    }
};