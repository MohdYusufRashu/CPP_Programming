class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        int x;
        bool flag=false;
        int y;
        for(char c : t){
            map[c]++;
        }
        int l=t.size();
        int i=0;
        int j=0;
        unordered_map<char,int> curr;
        int count=0;
        int ans=INT_MAX;
        string str="";
        while(j<s.size()){
            if(map.find(s[j])!=map.end()){
                curr[s[j]]++;
                if(curr[s[j]]<=map[s[j]]){
                        count++;
                }  
            }else{
                if(count==0){
                    i++;
                } 
            }
            /*if(count==map.size()){
                ans=min(ans,j-i+1);
            }*/
            while(count==l){
                if(curr.find(s[i])!=curr.end()){
                    if(j-i+1<ans){
                        x=i;
                        y=j;
                        flag=true;
                        ans=j-i+1;
                        //str=s.substr(i,ans);
                    }
                    curr[s[i]]--;
                    if(curr[s[i]]<map[s[i]]){
                        count--;
                    }
                }
                i++;
            }
            j++;
        }
        if(flag) str=s.substr(x,ans);
        return str;;
    }
};