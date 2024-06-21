class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && chars[j]==chars[i]){
                j++;
            }
            chars[ans++]=chars[i];
            if(j-i>1){
                int n=j-i;
                string s=to_string(n);
                for(int k=0;k<s.size();k++){
                    chars[ans++]=s[k];
                }
            }
            i=j-1;
        }
        return ans;
    }
};