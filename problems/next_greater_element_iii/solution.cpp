/*
6231540
     i
    i
   i 
     j

traverse each digit from right to left:
    if cur >= pre
        continue
    else break
    
find the next largest num: next_large

swap(cur, next_large)
6234510

reverse from i +1 to n - 1

*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size();
        int i = len - 2;
        // cout << str << endl;
        while (i >= 0 && str[i + 1] <= str[i]){
            --i;
            // cout << i << endl;
        }

        if (i < 0)
            return -1;
        
        int j = len - 1;
        while (j >= 0 && str[j] <= str[i])
            --j;
        
        // swap
        swap(str[i], str[j]);
        
        // reverse
        reverse(str.begin() + i + 1, str.end());
        
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};