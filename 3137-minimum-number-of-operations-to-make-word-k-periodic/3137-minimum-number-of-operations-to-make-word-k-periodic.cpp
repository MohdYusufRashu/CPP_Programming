class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        unordered_map<string,int> map;
        for(int i=0;i<n;i=i+k){
            map[word.substr(i,k)]++;
        }
        int maxCount=0;
        for(auto it : map){
            maxCount=max(it.second,maxCount);
        }
        return (n/k)-maxCount;
    }
};