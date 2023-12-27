class Solution {
public:
    
    /*int helper(string colors, vector<int>& neededTime,int index,char color){
        if(index==colors.size()){
            return 0;
        }
        int ans;
        if(colors[index]==color){
            ans=min(ans)
        }
    }*/
    int minCost(string colors, vector<int>& neededTime) {
        
        //helper(colors,neededTime,0,)
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
                //cout<<ans<<endl;
                sum=0;
                maxTime=0;
                i=j;
            }
        }
        return ans;
    }
};