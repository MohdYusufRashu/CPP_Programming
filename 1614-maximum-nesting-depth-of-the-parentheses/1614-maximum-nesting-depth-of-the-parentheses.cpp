class Solution {
public:
    int maxDepth(string s) {
        stack<char> st; 
        int ans = 0; 
        for (char c : s) { 
            if (c == '(') { 
                st.push(c); 
            } else if (c == ')') {
                ans = max((int)st.size(), ans);
                st.pop(); 
            }
        }
        return ans; 
    }
};