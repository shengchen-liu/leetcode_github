class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        mxFreq = max(mxFreq, ++freq[x]);
        m[freq[x]].push_back(x);
    }
    
    int pop() {
        int x = m[mxFreq].back(); 
        m[mxFreq].pop_back();
        if (m[freq[x]--].empty()) --mxFreq;
        return x;
    }

private:
    int mxFreq;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> m;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */