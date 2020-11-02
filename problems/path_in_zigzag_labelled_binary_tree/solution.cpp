/*
            1 
          /  \
      2           3
     / \         / \
    4  5        6   7
   /|  |\     / |   |  \
  8 9  10 11 12 13  (14) 15
  
  14-> 14/2= 7 -> 7/2=3 -> 3/2 => 1
  
              1                      layer: 0
          /  \                              
         3           2                      1
       / \         / \
      4  5        6   7                     2
   / |   | \    / |   |  \
  15 (14)  13 12 11 10  9   8               3

1. given label, we need to find its current layer.[2^i, 2^(i+1))
    check label >= 2^(i + 1)
2.
at current val, if its row is reversed => layer:= odd
    true: find its inversed val  e.g 14 => 9
    false: (1) find its parent val.  4.parent = 4/2 = 2. (2) find the inversed val of parent.  e.g 2.inverse"= 3
    
at layer i, range [2^i, 2^(i+1) - 1]
i:= even
node j[2]
   /   \
  L     R 
*/
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // step 1. find label's layer
        int layer = 0;
        int node_count = 1;
        while (label >= node_count * 2) {// label is not at this layer
            ++layer;
            node_count *= 2;
        }
        
        // step 2.  find parents
        vector<int> res;
        while (label != 0) {
            res.push_back(label);
            int level_max = pow(2, layer + 1) - 1;
            int level_min = pow(2, layer);
            label = (level_max + level_min - label) / 2;
            --layer;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};