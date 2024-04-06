class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        vector<int> flag(n,0);
        string ans;
        stack<int> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(i);
                flag[i]=1;
            }else if(s[i]==')'){
                if(!st.empty()){
                    flag[st.top()]=0;
                    st.pop();
                }else{
                    flag[i]=1;
                }
            }
            i++;
        }
        for(int i=0;i<n;i++){
            if(!flag[i]){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};