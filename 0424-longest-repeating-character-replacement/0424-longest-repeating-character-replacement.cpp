class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int x=0;x<26;x++){
            char c='A' + x;
            int count=0;
            int K=k;
            int i=0,j=0;
            while(j<n){
                if(s[j]==c){
                    j++;
                }else{
                    if(K>0){
                        j++;
                        K--;
                    }else{
                        while(s[i]==c){
                            i++;
                        }
                        i++;
                        K++;
                    }
                }
               ans=max(ans,j-i); 
            }
        }
        return ans;
    }
};