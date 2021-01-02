/*
 [[78],[4,64],[91]]
vector<int> (101) a
78: {0}
4: {64}
91: {0}
for i in range(arr.size):
    find m[i].
        if false => return false
        if true :
            for j = 0 : m[i]
                check if arr[i] == m[j]
                if false return false
                if true: ++i, ++j
return true
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int ,vector<int>> m;
        for (auto a : pieces) {
            m[a[0]] = a;
        }
        
        // loop
        int i = 0;
        while (i < arr.size()) {
            int val = arr[i]; //91, 4
            if (!m.count(val)) {
                return false;
            } else{
                auto tmp = m[val]; // {91}, {4, 64}
                int n = tmp.size(); //1, 2
                int j = 0;
                while (j < n) {
                    if (arr[i] != tmp[j]){
                        // cout << arr[i] << "," << tmp[j];
                        return false;
                    }
                    ++i;
                    ++j;
                }
            }
        }
        return true;
    }
};