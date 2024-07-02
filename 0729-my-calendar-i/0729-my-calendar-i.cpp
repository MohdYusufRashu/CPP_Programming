class MyCalendar {
public:
    vector<vector<int>> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto v : intervals){
            if(!(end<=v[0] || start>=v[1])){
                return false;
            }
        }
        intervals.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */