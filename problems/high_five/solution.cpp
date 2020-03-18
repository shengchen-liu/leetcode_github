/**
[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
1: 91, 92, 60, 65, 87, 100
2: 93, 97, 77, 100, 76
min_heap, size of 5 for each student
**/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> result;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hashmap;
        for (auto& item : items) {
            int id = item[0];
            int score = item[1];
            if (!hashmap.count(id)) {
                result.push_back({id});
            }
            if (hashmap[id].size() < 5) {
                hashmap[id].push(score);
            } else { // == 5
                if (score > hashmap[id].top()) {
                    hashmap[id].pop();
                    hashmap[id].push(score);
                }
                
            }
        }
        for (vector<int>& item : result) {
            int id = item[0];
            int total = 0;
            while (!hashmap[id].empty()) {
                total += hashmap[id].top();
                hashmap[id].pop();
            }
            item.push_back(total/5);
        }
        return result;
    }
};