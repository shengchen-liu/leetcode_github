/**
f: [0, 0, 0,..., 0] 26 0's
iterate the s => [0, 1, 1, 1, 0,..., 0]

for word in words:
    f(count)
sort
**/
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fr(12, 0);
        int f;
        vector<int> q;
        for (int i = 0; i < words.size(); ++i) {
            f = getf(words[i]);
            fr[f]++;
        }
        
        // find cumulative frequency
        for (int i = 9; i >=0; --i) {
            fr[i] = fr[i] + fr[i + 1];
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            f = getf(queries[i]);
            q.push_back(fr[f + 1]);
        }
        
        return q;
    }
    
    int getf(string &s) {
        vector<int> bucket(26);
        for (char c : s) {
            int idx = c -'a';
            ++bucket[idx];
        }
        
        for (int i : bucket) {
            if (i > 0) {
                return i;
            }
        }
        return 0;
    }
};