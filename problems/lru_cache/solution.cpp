/*
hashmap: key : ptr to a list member
list: pair<key, val>

m:
3 : ptr->{3, 3}
4 : ptr->{4,4}

list:
{1,1}
{1,1}, {2, 2}
{2,2}, {1, 1}
{1,1}, {3, 3}
{3,3}, {4, 4}
{4,4}, {3,3}
{3,3}, {4,4}


*/
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // hashmap
        // no exist, exist
        auto it = m.find(key);  // pair<int, iterator>
        if (it == m.end())
            return -1;
        
        // update list
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        // exist
        // update l
        if (it != m.end()){
            it->second->second = value;
            // move to the front of list
            l.splice(l.begin(), l, it->second);
            return;
        }
        // no exist
        // reach to the max cap
        if (l.size() == cap){
            auto node = l.back();
            m.erase(node.first);
            l.pop_back();
        }
        
        // insert
        l.push_front({key, value});
        m[key] = l.begin();            
    }

private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */