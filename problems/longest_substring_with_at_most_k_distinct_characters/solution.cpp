/*
eceba, k = 2
e   c   e   b   a      map              cnt   maxLen
ij                     e:1              1     1
i   j                  e:1 c:1          2     2
i       j              e:2 c:1          2     3
i           j          e:2 c:1 b:1      3     3
    i       j          e:1 c:1 b:1      3     3
        i   j          e:1 b:1          2     3
        i       j      e:1 b:1 a:1      3     3
            i   j      a:1 b:1          2     3
                ij     a:1              1     3

cntMap char : cnt
j = 0
i from 0 to n - 1:
    while j < n and cnt <= k:
        if (!cntMap.count(s[j]))
            ++cnt
        cntMap[s[j]]++
        ++j
    if cnt <= k:
        maxLen = max(maxLen, j - i)
    if cntMap[s[i]] == 1:
        --cnt
    cntMap[s[i]]--;

*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cntMap;
        int i = 0;
        int maxLen = 0;
        for (int j = 0; j < s.size(); ++j) {
            cntMap[s[j]]++;
            while (i <= j && cntMap.size() > k) {
                cntMap[s[i]]--;
                if (cntMap[s[i]] == 0)
                    cntMap.erase(s[i]);
                ++i;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};