class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count=0;
        for (char c : s) { 
            if (c == '(') { 
                count++;
            }else if(c==')'){
                count--;
            }
            ans=max(ans,count);
        }
        return ans; 
    }
};