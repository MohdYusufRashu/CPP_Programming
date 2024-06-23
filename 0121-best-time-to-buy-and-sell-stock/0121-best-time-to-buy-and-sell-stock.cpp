class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sm=prices[0];
        int profit=INT_MIN;
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-sm);
            sm=min(sm,prices[i]);
        }
        if(profit<0) return 0;
        return profit;
    }
};