class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int mx=INT_MIN;
        int i=0,j=0;
        int sum=0;
        int start,end;
        while(j<n){
            //cout<<i<<" "<<j<<endl;
            while((j-i)<minutes){
                if(grumpy[j]==1) sum+=customers[j];
                j++;
            }
            if(j>n) break;
            if(sum>mx){
                start=i;
                end=j-1;
                mx=sum;
            }
            if(grumpy[i]==1) sum-=customers[i]; 
            i++;
        }
        int ans=0;
        //cout<<start<<" "<<end;
        for(int i=0;i<n;i++){
            if((i>=start && i<=end) || grumpy[i]==0){
                ans+=customers[i];
            }
        }
        return ans;
    }
};