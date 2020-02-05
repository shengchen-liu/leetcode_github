class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start= 0;
        int total = 0;
        int remain = 0;
        for (int i = 0; i <gas.size(); ++i) { //i: 2, 3, 4 
            total += gas[i] - cost[i]; // total: -3 + 5 -2 = 0
            remain += gas[i] - cost[i]; // remain: 3 + 5-2 = 6
            if (remain < 0) {
                start = i + 1; // start: 1, 2, 3
                remain = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};