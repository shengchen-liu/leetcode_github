class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        dq.push_front(val);
        if (dq.size() > this->size) {
            windowSum = windowSum - dq.back() + val;
            dq.pop_back();
        } else {
            windowSum += val;
        }
        int n = dq.size();
        return (double) windowSum / n;
    }
private:
    deque<int> dq;
    int size = 0;
    int windowSum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */