class StockSpanner {
public:
    
    stack<int> st;
    vector<int> nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        nums.push_back(price);
        int ans;
        while(!st.empty() && nums[st.top()]<=price){
            st.pop();
        }
        if(st.empty()) ans=nums.size();
        else ans=(nums.size())-(st.top())-1;
        st.push(nums.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */