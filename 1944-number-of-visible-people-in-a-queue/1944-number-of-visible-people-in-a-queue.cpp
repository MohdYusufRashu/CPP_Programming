class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> output(n);
        int count=0;
        for(int i=n-1;i>=0;i--){
            count=0;
            while(!st.empty() && st.top()<heights[i]){
                st.pop();
                count++;
            }
            if(st.empty()){
                output[i]=count;
            }else{
                output[i]=count+1;
            }
            st.push(heights[i]);
        }
        return output;
    }
};