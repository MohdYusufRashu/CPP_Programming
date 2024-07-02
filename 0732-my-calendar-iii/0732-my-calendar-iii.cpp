class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int sum=0;
        int ans=0;
        for(auto it : m){
            sum+=it.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */