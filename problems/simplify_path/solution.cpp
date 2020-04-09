/**
1. must always begin with a slash /
2.  must be only a single slash / between two directory names.
3. The last directory name (if it exists) must not end with a trailing /
4.  the canonical path must be the shortest string representing the absolute path.

cases
/->dir_name => /dir_name
/=>.. => parent dir
/=> . => current dir
/->/  => /

stack
"/a/./b/../../c/"
[a, b]
[a]
[c]


"/a//b////c/d//././/.."
[a]
[a, b]
[a, b, c]
[a, b, c, d]
[a, b, c] => pour into another stack [c, b, a]
**/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i; // find the first non '/'
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i; // find the next '/'
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back();
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};