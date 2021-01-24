class Solution {
public:
int minCharacters(string a, string b) {
    int res = INT_MAX, sza = a.size(), szb = b.size();
    int cnt1[26] = {}, cnt2[26] = {};
    for (auto ch : a)
        ++cnt1[ch - 'a'];
    for (auto ch : b)
        ++cnt2[ch - 'a'];
    for (auto ch = 1; ch < 26; ++ch) {
        res = min({res, 
            accumulate(begin(cnt1) + ch, end(cnt1), 0) +
                accumulate(begin(cnt2), begin(cnt2) + ch, 0), 
            accumulate(begin(cnt2) + ch, end(cnt2), 0) +
                accumulate(begin(cnt1), begin(cnt1) + ch, 0),                  
            sza - cnt1[ch] + szb - cnt2[ch]});
    }
    return res;
}
};