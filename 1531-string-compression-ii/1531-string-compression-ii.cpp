class Solution {
public:
    
    /*string encode(string s){
        string ans="";
        for(int i=0;i<s.size();i++){
            int j=i+1;
            while(j<s.size() && s[j]==s[i]){
                j++;
            }
            ans=ans + s[i];
            int count=j-i;
            if(count>1){
                if(count>9){
                    ans = ans + to_string(count);
                }else{
                    ans=ans + char(count + '0');
                }  
            }
            i=j-1;
        }
        cout<<ans<<endl;
        return ans;
    }*/
    
    /*int helper(string s,int k,int index){
        if(k==0 || index>=s.size()){
            return s.size()-index;
        }
        if(index==s.size()-1){
            return 0;
        }
        int ans=0;
        if(s[index+1]>='0' && s[index+1]<='9'){
            int temp=index+1;
            string numString="";
            while(temp<s.size() && s[temp]>='0' && s[temp]<='9'){
                numString+=s[temp];
                temp++;
            }
            cout<<numString<<endl;
            int num=stoi(numString);
            int oneless=INT_MAX,twoless=INT_MAX,threeless=INT_MAX;
            if(num>9){
                if(k>=num-10+1){
                    oneless=helper(s,k-(num-10+1),index+3);
                    if(k>=num-1){
                        twoless=helper(s,k-(num-1),index+3);
                    }
                    if(k>=num){
                        threeless=helper(s,k-num,index+3);
                    }
                }
            }else{
                if(k>=num-1){
                        twoless=helper(s,k-(num-1),index+2);
                    }
                    if(k>=num){
                        threeless=helper(s,k-num,index+2);
                    }
                }
            ans=min(oneless,min(twoless,threeless));
        }else{
            ans=helper(s,k-1,index+1);
        }
        return ans;
        
    }*/
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,101));
        for(int i=n;i>=0;i--){
            for(int j=0;j<=k;j++){
                if(i==n){
                   dp[i][j]=0;
                    continue;
                }
                //delete the ith character
                if(j>0){
                    dp[i][j]=dp[i+1][j-1];
                }
                //keep the character
                int count=0,diff=0;
                for(int x=i;x<n;x++){
                    if(s[x]==s[i]) count++;
                    else diff++;
                    if(j>=diff){
                        int temp;
                        if(count==1) temp=1;
                        else if(count<=9) temp=2;
                        else if(count<=99) temp=3;
                        else temp=4;
                        dp[i][j]=min(dp[i][j],temp + dp[x+1][j-diff]);
                    }else{
                        break;
                    }
                } 
            }
        }
        return dp[0][k];
    }
};