class Solution {
public:
    
    vector<int> lps(string s){
        int n=s.size();
        vector<int> prefix(n,0);
        prefix[0]=0;
        for(int i=1;i<n;i++){
            int j=prefix[i-1];
            while(j>0 && s[i]!=s[j]){
                j=prefix[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            prefix[i]=j;
        }
        return prefix;
    }
    string shortestPalindrome(string s) {
        int n=s.size(); 
        string temp=s;
        reverse(temp.begin(),temp.end());
        temp=s+"$"+temp;
        //cout<<"yes";
        vector<int> v=lps(temp);
        //cout<<"yes";
        //int maxi=*max_element(v.begin(),v.end());
        //cout<<maxi;
        int maxi=v[v.size()-1];
        temp=s.substr(maxi);
        reverse(temp.begin(),temp.end());
        s=temp+s;
        return s;
        
    }
};