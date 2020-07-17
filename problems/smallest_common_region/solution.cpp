class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        vector<string> par1;
        vector<string> par2;

        for (int i = 0; i < regions.size(); ++i) {
            for (int j = 1; j < regions[i].size(); ++j) {
                parent[regions[i][j]] = regions[i][0];
            }
        }
        
        while (region1.size() != 0) {
            par1.push_back(region1);
            region1 = parent[region1];
        }
        
        while (region2.size() != 0) {
            par2.push_back(region2);
            region2 = parent[region2];
        }
        
        for (auto v1 : par1) {
            for (auto v2 : par2) {
                if (v1 == v2) return v1;
            }
        }
        
        return "";
    }
};