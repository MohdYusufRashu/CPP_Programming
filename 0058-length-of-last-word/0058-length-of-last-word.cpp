class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int ans=0;
        int i=0,j=0;
        while(j<n){
            if(s[j]!=' '){
                ans=j-i+1;
            }else{
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};