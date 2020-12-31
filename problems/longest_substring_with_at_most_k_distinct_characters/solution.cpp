class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() == 0 || k == 0) {
            return 0;
        }
        
        int left = 0, right = 0, cnt = 0;
        int char_set[256] = {0};
        int ans = 0;
        
        while (right < s.size()) {
            // 统计right指向的字符
            // 当字符在窗口内第一次出现时，字符种类数+1，该字符出现次数+1
            if (char_set[s[right]] == 0) {
                cnt++;
            }
            char_set[s[right]]++;
            right++;
            
            // 向右移动left，保持窗口内只有k种不同的字符
            while (cnt > k) {
                char_set[s[left]]--;
                // 当该字符在本窗口不再出现时，字符种类数-1
                if (char_set[s[left]] == 0) {
                    cnt--;
                }
                left++;
            }
            
            // 更新答案
            ans = max(ans, right - left);
        }
        return ans;
    }
};