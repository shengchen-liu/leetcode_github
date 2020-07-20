class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> score(N + 1);
        for (auto a : trust) {
            score[a[0]]--;
            score[a[1]]++;
        }
        
        for (int i = 1; i <= N; ++i) {
            if (score[i] ==  N - 1) return i;
        }
        
        return -1;
    }
};