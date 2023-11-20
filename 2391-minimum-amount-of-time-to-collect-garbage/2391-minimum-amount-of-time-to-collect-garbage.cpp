class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<vector<int>> temp(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            for(char c:garbage[i]){
                if(c=='P') temp[i][0]++;
                else if(c=='G') temp[i][1]++;
                else temp[i][2]++;
            }
        }
        int ans=0;
        for(int k=0;k<3;k++){
            int tempVal=0;
            int min=0;
            for(int i=0;i<n;i++){
                if(temp[i][k]){
                    tempVal+=temp[i][k];
                    tempVal=tempVal+min;
                    min=0;
                }
                if(i<n-1)
                min=min+travel[i];
            }
            ans=ans+tempVal;
        }
        return ans;
    }
};