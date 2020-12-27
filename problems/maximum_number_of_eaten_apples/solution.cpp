/*
apples = [1,2,3,5,2], days = [3,2,1,4,2]
day0: 1
*/
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // map
        map<int, int> rem;  //{day, cnt}

        int i = 0;
        int n = apples.size();
        int res = 0;
        while (true) {
            // update rem
            if (i < n) {
                // new apples
                int day = days[i];
                rem[i + day] += apples[i];  // 3: 1
                // cout << rem[i + day] << endl;
            }
            // check rot
            while (!rem.empty()) {
                auto it = rem.begin();
                int key = it->first;
                int val = it->second;
                if (key <= i || val <= 0){
                    // cout << key << endl;
                    rem.erase(key);
                } else{
                    break;
                }
            }


            // cout << rem.begin()->second << endl;
            if (rem.empty() && i >= n)
                break;
            // eat 1
            if (!rem.empty()) {
                int key = rem.begin()->first;
                rem[key]--;
                if (rem[key] <= 0)
                    rem.erase(key);
                ++res;
            }
            ++i;

        }
        return res;
    }
};