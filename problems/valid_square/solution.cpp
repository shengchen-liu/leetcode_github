class Solution {
public:
    double dist(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       // sort by x, if equal, sort by y
        vector<vector<int>> points = {p1, p2, p3, p4};
        
        sort(points.begin(), points.end());
        
        // compare 4 edges
        if (dist(points[0], points[1]) != 0 && 
            dist(points[0], points[1]) == dist(points[1], points[3]) &&
            dist(points[1], points[3]) == dist(points[3], points[2]) &&
            dist(points[3], points[2]) == dist(points[2], points[0]) &&
            dist(points[0], points[3]) == dist(points[1], points[2]) // compare 2 diagnols
           )
        return true;
        
        return false;
    }
};