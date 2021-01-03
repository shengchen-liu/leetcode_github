/*
box Types:
[1,3],
[2,2],
[3,1]

sort by box size
3: 1
2: 2
1: 3

3 + 2 + 2 + 1

10: 5
9 : 3
7 : 4
5 : 2

truckSize = 10

10 * 5 + 9 *3 + 7 * 2
50 + 27 + 14 = 91

maximum total number of units

*/class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // map
        map<int, int> m;
        for (auto a : boxTypes) {
            int cnt = a[0]; // 5
            int size = -a[1];  // -10
            m[size] += cnt;
        }
        
        int rem = truckSize;
        int res = 0;
        for (auto a : m) {
            //termination
            if (rem == 0)
                break;
            int cnt = a.second;
            int units = -a.first;

            // cout << units << "," << cnt << endl;
            if (cnt <= rem) {
                res += cnt * units;
                rem -= cnt;
            } else {
                res += rem * units;
                rem = 0;
            }
        }
        
        return res;
    }
};