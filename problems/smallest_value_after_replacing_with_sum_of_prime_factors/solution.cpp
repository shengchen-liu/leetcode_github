/*
15

15 = 3 * 5  find all prime factors -> add
*/
class Solution {
public:
    int smallestValue(int n) {
        int res = n;
        int tmp = n;
        while (true){
            res = getPrimeSum(tmp);
            if (res == tmp)
                break;
            tmp = res;
        }
        return res;
    }
    
    // bool isPrime(int n) {
    //     if (n <= 1)
    //         return false;
    //     for (int i = 2; i <= sqrt(n); ++i) {
    //         if (n % i == 0)
    //             return false;
    //     }
    //     return true;
    // }
    
    int getPrimeSum(int n) {
        int sum = 0;
        int c = 2;
        while (n > 1) {
            if (n % c == 0) {
                sum += c;
                n /= c;
            } else {
                c++;
            }
        }
        return sum;
    }
};