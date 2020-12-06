class Solution:
    def concatenatedBinary(self, n: int) -> int:
        size = 0   #bit length of addends
        result = 0   # long accumulator
        for i in range(1, n + 1):    
            if i & (i - 1) == 0:    #for powers of two we increase bit length
                size += 1
            result = ((result << size) | i) % 1000000007   #shift accumulator left and fill low bits with new addend
        return result;