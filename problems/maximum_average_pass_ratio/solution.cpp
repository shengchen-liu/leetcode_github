/*
2d int arrar classes
[pass_i, total_i]

pass   total
1+2    2+2
3      5
2      2

extraStudents = 2

average pass ratio => maximize 
pass ratio : (1/2 + 3/5 + 2/2) / 3 = ?
pass ratio : (3/4 + 3/5 + 2/2) / 3 = 0.78333

Q:
suppose we only have 1 extraStudent: which class should we add this student to?
pass   total   pass_new total_new   profit= pass_new / total_new - pass / total
1+1    2+1     2        3           2/3 - 1/2 = 0.166666667
3+1    5+1     4        6           4/6 - 3/5 = 0.066666667
2+1    2+1     3        3           3/3 - 2/2 = 0 

pass   total
1      2
3+1    5+1
2      2

pass   total
1      2
3      5
2+1    2+1

data structure => max_heap (profit, {pass, total})

for each student : students:
    // add 1 student to which group?
    generatye max_heap
    get top of the max_heap
    update the top
    push back to the max_heap
    

*/
class Solution {
public:
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto profit = [&](double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    };
    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq; // profit, [pass, total]
    for (auto &c : classes) {
        total += (double) c[0] / c[1];
        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
    }
    while (extraStudents--) {
        auto [score, c] = pq.top(); pq.pop();
        total += (double) (c[0] + 1) / (c[1] + 1) - (double) c[0] / c[1];
        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
    }
    return total / classes.size();
}
        
};