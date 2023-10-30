class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> arr;
        for(int i=0;i<gas.size();i++){
            arr.push_back(gas[i]-cost[i]);
        }
        arr.insert(arr.end(),arr.begin(),arr.end());
        int j=0;
        int i=0;
        int sum=0;
        while(j<arr.size()){
            sum=sum+arr[j];
            if(sum>=0){
               j++; 
            } 
            else{
               i=++j;
                sum=0;
            } 
            if((j-i)==n) return i;
        }
        return -1;
    }
};