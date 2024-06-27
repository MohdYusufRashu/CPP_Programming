class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int n1=nums[0],n1Count=1;
        int n2=-1,n2Count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==n1){
                n1Count++;
            }
            else if(nums[i]==n2){
                n2Count++;
            }
            else if(n1Count==0){
                n1=nums[i];
                n1Count=1;
            }else if(n2Count==0){
                n2=nums[i];
                n2Count=1;
            }else{
                n1Count--;
                n2Count--;
            }
        }
        vector<int> ans;
        if(n1Count>0){
            int c=count(nums.begin(),nums.end(),n1);
            if(c>n/3) ans.push_back(n1);
        }
        if(n2Count>0){
            int c=count(nums.begin(),nums.end(),n2);
            if(c>n/3) ans.push_back(n2);
        }
        return ans;
    }
};