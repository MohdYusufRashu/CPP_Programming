class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            int count=0;
            while(num){
                count+=num%2;
                num=num>>1;
            }
            pq.push({count,arr[i]});
        }
        vector<int> output;
        while(!pq.empty()){
            output.push_back(pq.top().second);
            pq.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
};