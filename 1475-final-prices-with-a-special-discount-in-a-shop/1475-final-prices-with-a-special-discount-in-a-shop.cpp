class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        //vector<int> nextSmaller(n);
        vector<int> output(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                //nextSmaller[i]=-1;
                output[i]=prices[i];
            }else{
                //nextSmaller[i]=st.top();
                output[i]=prices[i]-st.top();
            }
            st.push(prices[i]);
        }
        return output;
    }
};