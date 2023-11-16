class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int i=0;
        string ans="";
        for(auto it : nums){
            int temp=it[i]-'0';
            char c=!temp + '0';
            ans=ans + c;
            i++;
        }
        return ans;
    }
};