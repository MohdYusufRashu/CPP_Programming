class Solution {
public:
    
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        long long ans=0;
        unordered_map<int,long long> freq;
        vector<int> revDiff(nums.size());
        for(int i=0;i<n;i++){
            string str=to_string(nums[i]);
            reverse(str.begin(),str.end());
            int revNum=stoi(str);
            revDiff[i]=nums[i]-revNum;
            freq[revDiff[i]]++;
        }
        for(auto it : freq){
            cout<<it.second<<" ";
            if(it.second>1){
                if(it.second%2==0){
                    ans+=((it.second/2)*(it.second-1))%mod;
                }else{
                    ans+=(it.second*((it.second-1)/2))%mod;
                }   
                ans=ans%mod;
                cout<<endl<<ans;
            }
        }
        return (int)ans;
        
    }
};