class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char> > graph = constructGraph(words);
        if (!graph.size()) {
            return "";
        }

        return topologicalSorting(graph);
    }
    
    map<char, set<char> > constructGraph(vector<string>& words) {
        map<char, set<char> > graph;
        // create nodes
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                if (graph.find(c) == graph.end()) {
                    set<char> temp;
                    graph[c] = temp;
                }
            }
        }

        // create edges
        for (int i = 0; i < words.size() - 1; i++) {
            int index = 0;
            while (index < words[i].size() && index < words[i + 1].size()) {
                if (words[i][index] != words[i + 1][index]) {
                    graph[words[i][index]].insert(words[i + 1][index]);
                    break;
                }
                index++;
            }
            if (index == min(words[i].size(), words[i + 1].size())) {
                if (words[i].size() > words[i + 1].size()) {
                    return map<char, set<char> >();
                }
            }
        }

        return graph;
    }
    
    map<char, int> getIndegree(map<char, set<char> >& graph) {
        map<char, int> indegree;
        map<char, set<char> >::iterator iter;
        iter = graph.begin();
        while (iter != graph.end()) {
            indegree[iter->first] = 0;
            iter++;
        }
        
        iter = graph.begin();
        while (iter != graph.end()) {
            set<char>::iterator _iter = (iter->second).begin();
            while (_iter != (iter->second).end()) {
                indegree[*_iter] = indegree[*_iter] + 1;
                _iter++;
            }
            iter++;
        }

        return indegree;
    }
    
    string topologicalSorting(map<char, set<char> > graph) {
        map<char, int> indegree = getIndegree(graph);

        priority_queue<char, vector<char>, greater<char> > Q;

        map<char, int>::iterator iter;
        iter = indegree.begin();
        while (iter != indegree.end()) {
            if (indegree[iter->first] == 0) {
                Q.push(iter->first);
            }
            iter++;
        }

        string s = "";
        while (Q.size()) {
            char head = Q.top();
            Q.pop();
            s += head;
            set<char>::iterator iter;
            iter = graph[head].begin();
            while (iter != graph[head].end()) {
                char neighbor = *iter;
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    Q.push(neighbor);
                }
                iter++;
            }
        }
        
        if (s.size() != indegree.size()) {
            return "";
        }
        return s;
    }
};