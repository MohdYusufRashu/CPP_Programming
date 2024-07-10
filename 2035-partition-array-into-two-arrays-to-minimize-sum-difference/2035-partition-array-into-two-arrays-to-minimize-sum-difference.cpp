class Solution {
public:
   
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        if(n&1) return -1;
        //int N=n;
        n/=2;
        vector<vector<int>> left(n+1);
        vector<vector<int>> right(n+1);
        for(int mask=0;mask<(1<<n);mask++){
            int count=0;
            int ls=0,rs=0;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    count++;
                    ls+=nums[j];
                    rs+=nums[j+n];
                }
            }
            left[count].push_back(ls);
            right[count].push_back(rs);
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            sort(right[i].begin(),right[i].end());
        }
        int res=INT_MAX;
        for(int s1=0;s1<n+1;s1++){
            int s2=n-s1;
            int target=sum/2;
            for(int j=0;j<left[s1].size();j++){
                int req=target - left[s1][j];
                int lb=lower_bound(right[s2].begin(),right[s2].end(),req)-right[s2].begin();
                if(lb!=right[s2].size()) res=min(res,abs(right[s2][lb]+left[s1][j] -(sum-(right[s2][lb]+left[s1][j]))));
            }
            
        }
        return res;
        
    }
};