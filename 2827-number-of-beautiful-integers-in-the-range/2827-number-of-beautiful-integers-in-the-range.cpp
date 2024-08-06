class Solution {
public:
    
    int dp[10][2][11][11][21];
    
    int solve(string& s,int index,int tight,int ec,int oc,int rem,int az,int k){
        if(index==s.size()){
            if(ec==oc && rem==0) return 1;
            return 0;
        }
        if(dp[index][tight][ec][oc][rem]!=-1) return dp[index][tight][ec][oc][rem];
        int end;
        if(tight==0) end=9;
        else end=s[index]-'0';
        int count=0;
        for(int i=0;i<=end;i++){
            int newtight=tight && (i==end);
            int newrem=(rem*10 + i)%k;
            int newaz=az && (i==0);
            if(i%2==0){
                int temp=0;
                if(newaz==0) temp=1;;
                count+=solve(s,index+1,newtight,ec+temp,oc,newrem,newaz,k);
            }else{
                count+=solve(s,index+1,newtight,ec,oc+1,newrem,newaz,k);
            }
        }
        return dp[index][tight][ec][oc][rem]=count;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        string str=to_string(high);
        int h=solve(str,0,1,0,0,0,1,k);
        memset(dp, -1, sizeof(dp));
        str=to_string(low-1);
        int l=solve(str,0,1,0,0,0,1,k); 
        return h-l;
    }
};