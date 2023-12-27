class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=0;
        int maxTime=0;
        int sum=0;
        int ans=0;
        while(j<colors.size()){
            if(colors[i]==colors[j]){
                sum+=neededTime[j];
                maxTime=max(maxTime,neededTime[j]);
                j++;
                if(j==colors.size()){
                    ans = ans + sum-maxTime;
                }
            }else{
                ans=ans + sum-maxTime;
                sum=0;
                maxTime=0;
                i=j;
            }
        }
        return ans;
    }
};