class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& A) {
        unordered_map<int, int> h;
        int n = A.size();
        for (int i = 0; i < target.size(); ++i)
            h[target[i]] = i;

        vector<int> stack;
        for (int a : A) {
            if (h.find(a) == h.end()) continue;
            if (stack.empty() || h[a] > stack.back()) {
                stack.push_back(h[a]);
                continue;
            }
            int left = 0, right = stack.size() - 1, mid;
            while (left < right) {
                mid = (left + right) / 2;
                if (stack[mid] < h[a])
                    left = mid + 1;
                else
                    right = mid;
            }
            stack[left] = h[a];
        }
        return target.size() - stack.size();
    }
};