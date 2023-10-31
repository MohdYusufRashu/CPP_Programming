class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int currXor=0;
        vector<int> output;
        for(int i=0;i<pref.size();i++){
            int val=pref[i]^currXor;
            output.push_back(val);
            currXor^=val;
        }
        return output;
    }
};