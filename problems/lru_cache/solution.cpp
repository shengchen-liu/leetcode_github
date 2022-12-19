/*
key: value
capacity: 2

1:1
2:2
get(1) -> 1
1:1
3:3

get(2) -> -1

3:3
4:4

get(1) -> -1

get(3)->3
4:4 (LRU)
3:3

get(4)->4
3:3 (LRU)
4:4

hashmap + linkedlist

linkedList:
1     ->    2  -> ....
(LRU)

hashmap: {key, ptr to the linkedlist}
1 : p_1
2 : p_2

put(key, value):
    if hashmap[key] not exisiting:
        new node(value)
        linkedlist append node
        hashmap[key] = node
    else:
        node = hashmap[key]
        node->value = value
        move node to tail of the linkedlist

get(key)
    if hashmap[key] not exisiting:
        return -1
    else:
        node = hashmap[key]
        move node to tail of the linkedlist
        return node->val

*/
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        ll.splice(ll.begin(), ll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            it->second->second = value;
            // move to the front
            ll.splice(ll.begin(), ll, it->second);
            return;
        }

        if (ll.size() == cap) {
            auto node =  ll.back();
            m.erase(node.first);
            ll.pop_back();
        }

        // insert
        ll.push_front({key, value});
        m[key] = ll.begin();
    }

private:
    int cap;
    list<pair<int, int>> ll;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */