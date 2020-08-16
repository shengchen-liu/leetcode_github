class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(-maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(-minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() ==  minHeap.size()) {
            return (maxHeap.top() - minHeap.top()) * 0.5;
        } else return maxHeap.top();
    }

private:
    // max_heap
    priority_queue<int> maxHeap;
    // heap_heap, reverse value 
    priority_queue<int> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */