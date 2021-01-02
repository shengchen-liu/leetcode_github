/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*
[1,[4,[6]]]
isInteger() : false
getList() -> vector<NestedInteger>
[1], [4, [6]]

[4, [6]]

f(cur, res):
    if cur.isInteger:
        append cur to res
        return
    
    vector = cur.getList()
    for each comp in the vector:
        f(comp, res)
        
iterative dfs
for each member in input:
    while (!member.isInteger):
        layer = member.getList()
*/

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        NestedInteger t = st.top();
        st.pop();
        return t.getInteger();
    }
    
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger t = st.top();
            if (t.isInteger())
                return true;
            st.pop();
            vector<NestedInteger> tmp = t.getList();
            for (int i = t.getList().size() - 1; i >= 0; --i) {
                st.push(tmp[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */