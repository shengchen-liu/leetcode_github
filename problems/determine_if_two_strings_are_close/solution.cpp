/*
2 strings.  close?
opt1: swap any two existing chars
opt2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
aacabb
selected char: 'a' -> 'b', 'b'->a
bbcbaa

do as many times as necessary

e.g: abc vs. bca
opt1: a[bc] -> a[cb]
opt1: acb -> bca

word1: 3,2, 1
word2: 2,2, 2
for i from 0 to m:
    compare w1[i] vs w2[i]
    
same types of chars
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        // w1, w2
        vector<int> w1(26, 0);
        vector<int> w2(26, 0);
        for (int i = 0; i < word1.size(); ++i) {
            int val1 = word1[i] - 'a';
            int val2 = word2[i] - 'a';
            w1[val1]++;
            w2[val2]++;
        }
        
        // sort w2, w2. max heap
        priority_queue<int> pq1, pq2;
        for (int i = 0; i < 26; ++i) {
            if ((w1[i] > 0 && w2[i] == 0) || (w1[i] == 0 && w2[i] > 0))
                return false;
            if (w1[i] > 0)
                pq1.push(w1[i]);
            if (w2[i] > 0) 
                pq2.push(w2[i]);
        }
        
        // compare each i form 0 to m
        if (pq1.size() != pq2.size())
            return false;
        
        for (int i = 0; i < pq1.size(); ++i) {
            int cnt1 = pq1.top(); pq1.pop();
            int cnt2 = pq2.top(); pq2.pop();
            if (cnt1 != cnt2) return false;
        }
        
        return true;
    }
};