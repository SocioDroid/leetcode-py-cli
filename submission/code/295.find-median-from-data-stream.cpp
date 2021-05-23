class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int counter = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == 0 || num < left.top())
            left.push(num);
        else
            right.push(num);
    
        if((int)left.size() - (int)right.size() > 1){
            right.push(left.top());
            left.pop();
        }else if((int)right.size() - (int)left.size() > 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {        
        if(left.size() == right.size())
            return (left.top() + right.top())/2.0;
        else if((int)left.size() >right.size())
            return left.top();
        else
            return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */