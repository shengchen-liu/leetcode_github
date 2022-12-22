/*
1
1,3
1,3,5 (sorted)

1, 3, 4, 5    find(7)
p        q

while (p < q)
nums[p] + nums[q] == 7  -> hashmap[7] = true, return true
nums[p] + nums[q] < 7 : p++
nums[p] + nums[q] > 7 : q--
*/
class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        nums[number]++;
    }
    
    bool find(int value) {
        for (auto tmp : nums) { // {key, count}
            int key = tmp.first;
            int count = tmp.second;
            long complement = (long)value - key;
            if (key != complement) {
                if (nums.count(complement))
                    return true;
            } else if (nums[key] > 1)
                return true;
        }
        return false;
    }

private:
    unordered_map<long, int> nums; // key, count
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */