/*
"coffee","donuts","time","toffee"
idea_a    idea_b    new_name               cnt
coffee    donouts   doffee conouts         1
coffee    time      toffee dime (x)        1
coffee
*/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // group by intials
        unordered_set<string> initialGroup[26];
        for (auto& idea : ideas) {
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        // Calculate number of valid names from every pair of groups
        long long ans = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int numOfMutual = 0;
                for (auto& ideaA : initialGroup[i]) {
                    if (initialGroup[j].count(ideaA))
                    ++numOfMutual;
                }

                ans += 2 * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }

        return ans;
    }
};