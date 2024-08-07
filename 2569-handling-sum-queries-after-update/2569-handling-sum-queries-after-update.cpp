class Solution {
public:
    
        vector<long long> seg;
        vector<long long> lz;
        
        void propagate(int ind,int low,int high){
            if(!lz[ind]) return;
            int len=high-low+1;
            if(lz[ind]&1) seg[ind]=len-seg[ind];
            if(low!=high){
                lz[2*ind+1]^=1;
                lz[2*ind+2]^=1;
            } 
            lz[ind]=0;
        }
        
        void build(int ind,int low,int high,vector<int>& arr){
            if(low==high){
                seg[ind]=arr[low];
                return;
            }
            int mid=(low+high*1LL)>>1;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        }
        
        long long find(int l,int r,int ind,int low,int high){
            propagate(ind,low,high);
            if(high<l || low>r) return 0;
            else if(low>=l && high<=r){
                return seg[ind];
            }else{
                int mid=(low+high*1LL)>>1;
                return find(l,r,2*ind+1,low,mid) + find(l,r,2*ind+2,mid+1,high);
            }
        }
        
        void update(int l,int r,int ind,int low,int high){
            propagate(ind,low,high);
            if(high<l || low>r) return;
            else if(low>=l && high<=r){
                lz[ind]^=1;
                propagate(ind,low,high);
            }else{
                int mid=(low+high)>>1;
                update(l,r,2*ind+1,low,mid);
                update(l,r,2*ind+2,mid+1,high);
                seg[ind]=seg[2*ind+1]+seg[2*ind+2];
            }
        }
    
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size();
        seg.resize(4*n,0);
        lz.resize(4*n,0);
        build(0,0,n-1,nums1);
        vector<long long> ans;
        long long sum=0;
        for(int i : nums2){
            sum+=i;
        }
        for(int i=0;i<queries.size();i++){
            int type=queries[i][0];
            if(type==1){
                update(queries[i][1],queries[i][2],0,0,n-1);
            }else if(type==2){
                long long ones=find(0,n-1,0,0,n-1);
                sum+=ones*queries[i][1];
            }else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};