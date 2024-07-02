class MyCalendar {
public:
    map<int,int> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto ub=intervals.upper_bound(start);
        if(ub==intervals.end() || ub->second >= end){
            intervals[end]=start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */