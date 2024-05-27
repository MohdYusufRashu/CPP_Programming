class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        //nextSmaller
        vector<int> nextSmaller(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nextSmaller[i]=n;
            else nextSmaller[i]=st.top();
            st.push(i);
        }
        stack<int> emptyStack;
        st.swap(emptyStack);

        
        //prevSmaller
        vector<int> prevSmaller(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) prevSmaller[i]=-1;
            else prevSmaller[i]=st.top();
            st.push(i);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            //cout<<i<<" "<<prevSmaller[i]<<" "<<nextSmaller[i]<<endl;
            int prevSize=i-prevSmaller[i];
            int forwSize=nextSmaller[i]-i;
            int width=prevSize+forwSize-1;
            ans=max(ans,width*heights[i]);
            //cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};