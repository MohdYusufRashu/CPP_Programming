class Solution {
public:
    
    bool possible(string s,int l){
        cout<<l<<" ";
        int n=s.size();
        int freq[26]={0};
        for(int i=0;i<l;i++){
            freq[s[i]-'a']++;
        }
        for(int i=l;i<n;i=i+l){
            int count[26]={0};
            for(int j=i;j<i+l;j++){
                count[s[j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(freq[k]!=count[k]) return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1;i<=n;i++){
            if(n%i==0){
                if(possible(s,i)) return i;
            }
        }
        return 0;
        /*int low=1;
        int high=s.size();
        while(low<=high){
            int mid=(low+high)>>1;
            //cout<<mid<<" ";
            if(possible(s,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;*/
    }
};