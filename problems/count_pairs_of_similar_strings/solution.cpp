/*
"aba","aabb","abcd","bac","aabc"
ab      ab    abcd    abc   abc

ab: 2
abc: 2
abcd: 1

"aabb","ab","ba" 'aab'
  ab    ab   ab   ab
ab: 4 => c4_2 = 4!/(2! * (4-1)!)

*/

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        unordered_map<string, int> m;
        for (auto word : words) {
            string key;
            for (int i = 0; i < 26; ++i) {
                key.push_back('0');
            }
            for (auto c : word) {
                int idx = c - 'a';
                key[idx] = '1';
            }
            m[key]++;
        }
        
        for (auto p : m) {
            int cnt = p.second;
            for (int i = 1; i < cnt; ++i) {
                res += i;
            }
        }
        return res;
    }
};