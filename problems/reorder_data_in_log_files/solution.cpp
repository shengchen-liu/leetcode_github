class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
    // use stable_sort as order of equivalent elements is preserved
    stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b){ 
        auto e1 = a.substr(a.find(' ')  + 1); // get words not including identifier
        auto e2 = b.substr(b.find(' ') + 1);

        // order if a || b are digit-logs
        if (isdigit(e1[0]) && isdigit(e2[0])) return false;
        if (isdigit(e1[0]) && !isdigit(e2[0])) return false;
        if (isdigit(e2[0]) && !isdigit(e1[0])) return true;

        // order if a && b are letter logs
        auto diff = e1.compare(e2);
        if (diff) return diff < 0;
        return a.compare(b) < 0;
    });
    return logs;
}
};