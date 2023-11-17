class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<string,int> map;
        vector<pair<int,int>> temp(26,{-1,-1});
        for(int i=0;i<s.size();i++){
            if(temp[s[i]-97].first==-1) temp[s[i]-97].first=i;
            temp[s[i]-97].second=i;
        }
        for(int i=1;i<s.size()-1;i++){
            for(int j=0;j<26;j++){
                if(temp[j].first!=-1 && temp[j].first<i && temp[j].second>i){
                    string str=to_string(s[i]);
                    char c=j+97;
                    str=c + str + c;
                    map[str]++;
                }
            }
            
        }
        return map.size();
    }
};