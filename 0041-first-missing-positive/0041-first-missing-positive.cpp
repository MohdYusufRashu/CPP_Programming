class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int me=INT_MAX;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                me=min(me,nums[i]);
            }
        }
        if(me!=1) return 1;
        cout<<"me = "<<me<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && i!=nums[i]-me){
                cout<<nums[i]<<"  : "<<nums[i]-me<<endl;
                bool flag=false;
                if(nums[i]-me>=n){
                     continue;
                 }
                 if(nums[i]!=nums[nums[i]-me]){
                     flag=true;
                 } 
                 
                swap(nums[i],nums[nums[i]-me]);
                if(flag) i--;
            }
        }
        for(int i=0;i<nums.size();i++){
            if((i+me) != nums[i]){
                return i+me;
            }
        }
        return nums[n-1]+1;
    }
};