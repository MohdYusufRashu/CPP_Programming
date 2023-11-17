class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        int i=0;
        vector<int> forw(n,0);
        vector<int> back(n,0);
        if(s[0]=='1') forw[0]=1;
        if(s[n-1]=='1') back[n-1]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                forw[i]=min(i+1,forw[i-1]+2);
            }else{
                forw[i]=forw[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                back[i]=min(n-i,back[i+1]+2);
            }else{
                back[i]=back[i+1];
            }
        }
        int ans=INT_MAX;
        ans=min(forw[n-1],back[0]);
        for(int i=0;i<n-2;i++){
            ans=min(ans,forw[i]+back[i+1]);
        }
        return ans;
            
    }
};