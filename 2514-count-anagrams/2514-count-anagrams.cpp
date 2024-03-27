class Solution {
public:
    
    int calinverse(long long x,int n){
        int mod=1e9+7;
        long long ans=1;
        while(n){
            if(n&1){
                ans=(ans*x)%mod;
                n--;
            }else{
                x=(x*x)%mod;
                n=n>>1;
            }
        }
        return ans;
    }
    
    int countAnagrams(string s) {
        int n=s.length();
        int mod=1e9+7;
        vector<int> fact(n+1,1);
        for(int i=1;i<n+1;i++){
            fact[i]=(fact[i-1]*1LL*i) % mod;
        }
        vector<int> inverseFact(n+1,1);
        for(int i=1;i<n+1;i++){
            inverseFact[i]=calinverse(fact[i],mod-2);
        }
        long long ans=1;
        int j=0;
        while(j<n){
            if(s[j]==' '){
                j++;
                continue;
            }
            int freq[26]={0};
            int i=j;
            while(j<n && s[j]!=' '){
                freq[s[j]-'a']++;
                j++;
            }
            int l=j-i;
            cout<<i<<" "<<j<<endl;
            ans=(ans*fact[l])%mod;
            for(int k=0;k<26;k++){
                if(freq[k]>1){
                    ans=(ans*inverseFact[freq[k]])%mod;
                }
            }
            
        }
        return ans;
    }
};