/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res, v;
        int n = schedule.size();
        for (auto a : schedule) {
            v.insert(v.end(), a.begin(), a.end());
        }
        
        auto comp = [](Interval &i1, Interval &i2){
            return i1.start > i2.start;
        };
        
        sort(v.begin(), v.end(), [](Interval &a, Interval &b) {return a.start < b.start;});
        
        Interval t = v[0];
        for (Interval i : v) {
            if (t.end < i.start) {
                res.push_back(Interval(t.end, i.start));
                t = i;
            } else {
                t = (t.end < i.end) ? i : t;
            }
        }
        return res;
    }
};