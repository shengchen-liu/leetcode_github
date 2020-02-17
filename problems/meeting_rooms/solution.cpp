class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        // e_i vs. s_{i + 1}
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int>& a, const vector<int>& b){return a[0] < b[0]; });
        
        vector<int> starts;
        vector<int> ends;
        for (auto it : intervals) {
            // s: it[0]  e:it[1]
            starts.push_back(it[0]);
            ends.push_back(it[1]);
        }
        
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (ends[i] > starts[i + 1]) return false;    
        }
        return true;
        
    }
};