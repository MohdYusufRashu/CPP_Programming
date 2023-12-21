class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        //int m1=*max_element(nums1.begin(),nums1.end());
        //int m2=*max_element(nums2.begin(),nums2.end());
        int m1=max(nums1[n-1],nums2[n-1]);
        int m2=min(nums1[n-1],nums2[n-1]);
        int op1=0;
        if(m2!=nums2[n-1]) op1++;
        bool impossible1=false;
        for(int i=0;i<n-1;i++){
            if(nums2[i]>m2){
                if(nums1[i]<=m2 && nums2[i]<=m1){
                    op1++;
                }else{
                    impossible1=true;
                    op1=INT_MAX;
                    break;
                }
            }
        }
        int op2=0;
        bool impossible2=false;
        if(m2!=nums1[n-1]) op2++;
        for(int i=0;i<n-1;i++){
            if(nums1[i]>m2){
                if(nums2[i]<=m2 && nums1[i]<=m1){
                    op2++;
                }else{
                    impossible2=true;
                    op2=INT_MAX;
                    break;
                }
            }
        }
        if(impossible1 || impossible2) return -1;
        return min(op1,op2);
    }
};