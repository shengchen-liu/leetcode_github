class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
            
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> cnt; // slope : count
            int same_points = 1;
            int max_points = 0;
            auto p1 = points[i];
            for (int j = i + 1; j < n; ++j) {
                auto p2 = points[j];
                if (p1[0] == p2[0] && p1[1] == p2[1])
                    ++same_points;
                else {
                    ++cnt[getSlope(p1, p2)];
                    max_points = max(max_points, cnt[getSlope(p1, p2)]); 
                }
            }
            res = max(res, same_points + max_points);

        }
        return res;
    }
    
    pair<int, int> getSlope(vector<int> p1, vector<int> p2) { // [dy, dx]
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        
        // horizontal
        if (dy == 0)
            return {p1[1], 0};
        // vertical
        if (dx == 0)
            return {0, p1[0]};
        
        int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }
    
    int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m % n); 
    }
};