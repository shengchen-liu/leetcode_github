/*
s="aab"
a:2
b:1
good

s="aaabbbcc"
a:3
b:3
c:2
delete chars in s => new s is "good"

1. hashmap to store the freq.  char : freq
2. sorted by freq
    3: 2
    2: 1
3. max heap => priorty_queue to store each freqs.
[3, 3, 2]
[5, 3, 3]

pq.larget vs. pq.second large: [5 vs 3]
    if !=: move on
    if ==: delete a char. update the pq
    

*/
class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        // hashmap -> vectorsize of 26
        vector<int> occurs(26, 0);
        for (char c : s) {
            occurs[c - 'a']++;
        }
        
        
        priority_queue<int> pq;
        for (int i : occurs) {
            if (i == 0) continue;
            pq.push(i);
        }
        
        // pq: [3, 3, 2]
        
        // iteration
        while (!pq.empty()) {
            int largest = pq.top();
            pq.pop();
            
            // this is the last element
            if (pq.empty())
                return res;
            
            // largest vs. sec largest
            if (largest == pq.top()){
                if (largest > 1) {
                    pq.push(largest - 1);
                }
                ++res;
            }
        }
        
        return res;
    }
};