class Solution {
public:
    
    class ST{
        vector<vector<vector<long long>>> segTree;
        int n;
        
        void build(vector<int>& nums,int index,int low,int high){
            if(low==high){
                segTree[index][0][0]=0;
                segTree[index][0][1]=-1e18;
                segTree[index][1][0]=-1e18;
                segTree[index][1][1]=nums[low];
                return;
            }
            int mid=(low+high)>>1;
            build(nums,2*index+1,low,mid);
            build(nums,2*index+2,mid+1,high);
            segTree[index][0][0]=max(segTree[2*index+1][0][0]+segTree[2*index+2][0][0],max(segTree[2*index+1][0][1]+segTree[2*index+2][0][0],segTree[2*index+1][0][0]+segTree[2*index+2][1][0]));
            segTree[index][0][1]=max(segTree[2*index+1][0][1]+segTree[2*index+2][0][1],max(segTree[2*index+1][0][0]+segTree[2*index+2][1][1],segTree[2*index+1][0][0]+segTree[2*index+2][0][1]));
            segTree[index][1][0]=max(segTree[2*index+1][1][1]+segTree[2*index+2][0][0],max(segTree[2*index+1][1][0]+segTree[2*index+2][0][0],segTree[2*index+1][1][0]+segTree[2*index+2][1][0]));
            segTree[index][1][1]=max(segTree[2*index+1][1][0]+segTree[2*index+2][0][1],max(segTree[2*index+1][1][1]+segTree[2*index+2][0][1],segTree[2*index+1][1][0]+segTree[2*index+2][1][1]));
        }
        
        
        void updateHelper(int index,int i,int val,int low,int high){
            if(low==high){
                segTree[index][1][1]=val;
                return;
            } 
            int mid=(low+high)>>1;
            if(i<=mid) updateHelper(2*index+1,i,val,low,mid);
            else updateHelper(2*index+2,i,val,mid+1,high);
            segTree[index][0][0]=max(segTree[2*index+1][0][0]+segTree[2*index+2][0][0],max(segTree[2*index+1][0][1]+segTree[2*index+2][0][0],segTree[2*index+1][0][0]+segTree[2*index+2][1][0]));
            segTree[index][0][1]=max(segTree[2*index+1][0][1]+segTree[2*index+2][0][1],max(segTree[2*index+1][0][0]+segTree[2*index+2][1][1],segTree[2*index+1][0][0]+segTree[2*index+2][0][1]));
            segTree[index][1][0]=max(segTree[2*index+1][1][1]+segTree[2*index+2][0][0],max(segTree[2*index+1][1][0]+segTree[2*index+2][0][0],segTree[2*index+1][1][0]+segTree[2*index+2][1][0]));
            segTree[index][1][1]=max(segTree[2*index+1][1][0]+segTree[2*index+2][0][1],max(segTree[2*index+1][1][1]+segTree[2*index+2][0][1],segTree[2*index+1][1][0]+segTree[2*index+2][1][1]));
        }
        
        public:
        ST(vector<int>& nums){
            n=nums.size();
            //segTree.resize(4*n+1,vector<long long>(4,vector<long long>(2)));
            
             segTree.resize(4 * n);

        // Resize each element in the outermost vector to a vector of size 4
        for (int i = 0; i < 4 * n; ++i) {
            segTree[i].resize(4);

            // Resize each element in the 2nd dimension to a vector of size 2
            for (int j = 0; j < 4; ++j) {
                segTree[i][j].resize(2);
            }
        }
            
            build(nums,0,0,n-1);
        }
        
        long long update(int i,int val){
            updateHelper(0,i,val,0,n-1);
            return max(segTree[0][0][0],max(segTree[0][0][1],max(segTree[0][1][0],segTree[0][1][1])));
        }
        
    };
    
    
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        long long ans=0;
        long long mod=1e9+7;
        ST s(nums);
        for(int i=0;i<queries.size();i++){
            ans+=s.update(queries[i][0],queries[i][1]);
        }
        ans=ans%mod;
        return (int)ans;
    }
};