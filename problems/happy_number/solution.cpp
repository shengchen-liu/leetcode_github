class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> visited;
        while (n != 1 && !visited.count(n)) {
            visited.insert(n);
            n = getNext(n);
        }
        return n == 1;   
    }
    
    int getNext(int n) {
        int temp = 0;
        while (n > 0){
            int digit = n % 10;
            temp += digit * digit;
            n = n / 10;
        }
        return temp;
    }
};