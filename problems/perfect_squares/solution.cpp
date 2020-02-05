class Solution {
public:
    int numSquares(int n) {
        vector<int> square_nums;
        for (int i = 0; i * i  <= n; ++i) {
            square_nums.push_back(i * i);
        }//  [1, 4, 9, 16, 25, ...]
        
        unordered_set<int> q;
        q.insert(n);
        
        int level = 0;
        while (q.size() > 0) {
            ++level;
            unordered_set<int> next_queue;
            for (int remain : q) {
                for (int square : square_nums) {
                    if (remain == square) {
                        return level;
                    } else if (remain < square) {
                        break;
                    } else {
                        next_queue.insert(remain - square);
                    }
                }
            }
            q = next_queue;
        }
    return level;
    }
};