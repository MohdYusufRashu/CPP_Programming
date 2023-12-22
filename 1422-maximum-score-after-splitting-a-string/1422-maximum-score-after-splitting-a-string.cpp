class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> zeros(n,0);
        vector<int> ones(n,0);
        int z=0,o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                z++;
            }else{
                o++;
            }
            zeros[i]=z;
            ones[i]=o;
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            ans=max(ans,zeros[i] + ones[n-1]-ones[i]);
        }
        return ans;
    }
};