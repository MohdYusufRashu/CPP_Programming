class Solution {
public:
    
    class node{
        public:
        int val=((1LL<<31)-1);
        node(){}
        node(int v){
            val=v;
        }
        void merge(const node& n1,const node& n2){
            val=n1.val & n2.val;
        }
    };
    
    class ST{
        vector<node> st;
        
        void buildHelper(vector<int>& arr,int index,int low,int high){
            //cout<<index<<" ";
            if(low==high){
                st[index].val=arr[low];
                return;
            } 
            int mid=(low+high)>>1;
            buildHelper(arr,2*index+1,low,mid);
            buildHelper(arr,2*index+2,mid+1,high);            
            st[index].merge(st[2*index+1],st[2*index+2]);
        }
        
        node queryHelper(int index,int l,int r,int low,int high){
            //cout<<index<<" ";
            //no overlap
            if(l>high || r<low) return node();
            
            //complete overlap
            else if(low>=l && high<=r){
                return st[index];
            }
            
            //partial overlap
            else{
                int mid=(low+high)>>1;
                node left=queryHelper(2*index+1,l,r,low,mid);
                node right=queryHelper(2*index+2,l,r,mid+1,high);
                node temp;
                temp.merge(left,right);
                return temp;
            }
        }
        
        public:
        ST(int n){
            st.resize(4*n);
        }
        
        void build(vector<int>& arr){
            buildHelper(arr,0,0,arr.size()-1);
        }
        
        int query(int l,int r,int n){
            return queryHelper(0,l,r,0,n-1).val;
        }
        
    };
    
    int minimumDifference(vector<int>& nums, int k) {
        
        int n=nums.size();
        ST s(n);
        s.build(nums);
        int low,high;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            //cout<<endl<<" i= "<<i<<endl;
            if(nums[i]<k){
                ans=min(ans,abs(k-nums[i]));
            }else{
                low=i;
                high=n-1;
                while(low<=high){
                    int mid=(low+high)>>1;
                    int val=s.query(i,mid,n);
                    ans=min(ans,abs(val-k));
                    if(val>k){
                        low=mid+1;
                    }else if(val<k){
                        high=mid-1;
                    }else{
                        break;
                    }
                } 
            }

        }
        return ans;
    }
};