class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // binary search
        if (!m.count(key)) return "";
        
        auto it = m.find(key);
        auto& timeMap = it->second;
        
        auto it2 = timeMap.upper_bound(timestamp);
        if (it2 == timeMap.begin()) {
            return "";
        }
        else {
            --it2;
            return it2->second;
        }
    }
    
private:
    unordered_map<string, map<int, string>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */