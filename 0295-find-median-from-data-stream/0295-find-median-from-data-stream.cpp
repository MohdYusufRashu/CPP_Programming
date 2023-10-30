class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
            return;
        }
        if(num<=left.top()){
            left.push(num);
            if(left.size()>right.size()+1){
                right.push(left.top());
                left.pop();
            }
        }else{
            right.push(num);
            if(right.size()>left.size()+1){
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()){
            return left.top();
        }else if(right.size()>left.size()){
            return right.top();
        }else{
            double ans=(1.0*(left.top()+right.top()))/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */