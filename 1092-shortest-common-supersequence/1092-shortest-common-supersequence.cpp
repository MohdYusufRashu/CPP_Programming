class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans;
        int s1=str1.size();
        int s2=str2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                } 
            }
        }
        string lcs;
        vector<bool> p1(s1);
        vector<bool> p2(s2);
        int i=s1,j=s2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs.push_back(str1[i-1]);
                p1[i-1]=true;
                p2[j-1]=true;
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs;
        i=0;
        j=0;
        while(i<s1 && j<s2){
            if(p1[i] && p2[j]){
                ans.push_back(str1[i]);
                i++;
                j++;
            }else if(p1[i]){
                ans.push_back(str2[j]);
                j++;
            }else{
                ans.push_back(str1[i]);
                i++;
            }
        }
        if(i<s1){
            ans=ans + str1.substr(i);
        }else if(j<s2){
            ans=ans + str2.substr(j);
        }
        return ans;
    }
};