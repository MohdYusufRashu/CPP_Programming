class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int ans=1;
        unordered_set<char> st;
        int i=0,j=1;
        st.insert(s[0]);
        while(j<s.size()){
            if(st.find(s[j])!=st.end()){
                while(s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            st.insert(s[j]);
            j++;
        }
        return ans;
    }
};