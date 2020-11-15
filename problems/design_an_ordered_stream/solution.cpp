/*
n pairs 
each pair (id, value)
id: range fomr 1 to n. no two ids are the same
value: string

returns several values based on its id in increasing order

n = 5                            ids          output
                                 *1
(3, ccccc)                       *1, 3        ""
(1, "aaaaa"), (3, ccccc)         *1, 3        "aaaaa"
                                 1, *2, 3   
(1, "aaaaa"), (2, "bbbbb),       1, *2, 3     "bbbbb", "ccccc"
(3, ccccc)
                                 1, 2, 3, *4 
                                 
(1, "aaaaa"), (2, "bbbbb),       1, 2, 3, *4, 5   ""
(3, ccccc), (5, "eeeee")


(1, "aaaaa"), (2, "bbbbb),       1, 2, 3, *4, 5   "ddddd", "eeeee"
(3, ccccc),(4, "ddddd"), 
(5, "eeeee")

observations:
1. obseravation:
    a struct to store the data based on ids: min_heap based on ids
2. ptr initialize to 1
   keep udating the ptr

*/
class OrderedStream {
public:
    OrderedStream(int n) {
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        pq.push({id, value}); // {3, "ccccc"}
        // check if the current ptr points to sth
        while (!pq.empty() && pq.top().first == ptr) {
            res.push_back(pq.top().second);
            pq.pop();
            ++ptr;
        }
        return res;
    }
    
    int ptr;
    
    // min heap
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; 
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */