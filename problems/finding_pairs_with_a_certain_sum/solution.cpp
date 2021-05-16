/*
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
nums1           nums2                           
0,1,2,3,4,5     0,1,2,3,4,5
1,1,2,2,2,3     1,4,5,2,5,4
count 7           

*/

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums1) {
            this->m1[num]++;
        }
        for (int num : nums2) {
            this->m2[num]++;
        }
    }
    
    void add(int index, int val) {
        int num_ori = this->nums2[index];
        this->nums2[index] += val;
        this->m2[num_ori]--;
        if (this->m2[num_ori] == 0)
            this->m2.erase(num_ori);
        this->m2[num_ori + val]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto it1 : this->m1) {
            int num1 = it1.first;
            int cnt1 = it1.second;
            if (this->m2.count(tot - num1))
                res += cnt1 * m2[tot - num1];
        }
        return res;
    }
    
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> m1, m2;  // number : cnt
    
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */