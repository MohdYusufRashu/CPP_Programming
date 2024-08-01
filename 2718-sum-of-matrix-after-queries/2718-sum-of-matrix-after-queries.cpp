class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int sz=queries.size();
        long long sum=0;
        int r=0;
        int c=0;
        unordered_set<int> row;
        unordered_set<int> col;
        for(int i=sz-1;i>=0;i--){
            int type=queries[i][0];
            int index=queries[i][1];
            int val=queries[i][2];
            if(type==0){
                if(row.find(index)!=row.end()) continue;
                sum+=(n-c)*val;
                r++;
                row.insert(index);
            }else{
                if(col.find(index)!=col.end()) continue;
                sum+=(n-r)*val;
                c++;
                col.insert(index);
            }
        }
        return sum;
    }
};