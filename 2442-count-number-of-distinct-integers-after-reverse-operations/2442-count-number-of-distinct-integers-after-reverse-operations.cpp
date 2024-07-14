class Solution {
public:
    
    int reverseNumber(int num){
        int ans=0;
        while(num){
            ans=ans*10 + num%10;
            num/=10;
        }
        return ans;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        int count=0;
        unordered_set<int> s;
        unordered_set<int> r;
        for(int i : nums){
            s.insert(i);
        }
        for(auto i : s){
            int revNum=reverseNumber(i);
            count++;
            if(s.find(revNum)==s.end() && r.find(revNum)==r.end()){
                count++;
                r.insert(revNum);
            }
        }
        return count;
    }
};