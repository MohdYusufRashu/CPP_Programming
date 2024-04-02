class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> map;
        bool freq[256]={false};
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                if(map[s[i]]!=t[i]) return false;
            }else{
                if(freq[t[i]]) return false;
                map[s[i]]=t[i];
                freq[t[i]]=true;
            } 
        }
        return true;
    }
};