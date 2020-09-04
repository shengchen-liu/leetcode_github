/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        const string hostName = startUrl.substr(0, startUrl.find('/', 7));
        vector<string> q{startUrl};
        unordered_set<string> seen(q.cbegin(), q.cend());
        for (int i = 0; i < q.size(); ++i){
            string url = q[i];
            for (auto& child : htmlParser.getUrls(url)) {
                if (child.find(hostName) == string::npos || seen.count(child)) continue;
                q.push_back(child);
                seen.insert(child);
            }
        }
        
        return q;

    }
};