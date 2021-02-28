/*
items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], 
ruleKey = "color", ruleValue = "silver"
*/
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        // check key
        int res = 0;
        for (auto item : items) {
            if (ruleKey == "type") {
                if (item[0] == ruleValue)
                    ++res;
            } else if (ruleKey == "color") {
                if (item[1] == ruleValue)
                    ++res;
            } else {
                 if (item[2] == ruleValue)
                    ++res;
            }   
        }
        return res;
    }
};