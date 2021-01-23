class Solution {
public:
    int numberOfSteps (int num) {
        if (num == 0)
            return 0;
        int cnt = 0;
        for (int powerOfTwo = 1; powerOfTwo <= num; powerOfTwo = powerOfTwo * 2) {
            if ((powerOfTwo & num) != 0)
                cnt += 2;
            else 
                cnt += 1;
        }
        return cnt - 1;
    }
};