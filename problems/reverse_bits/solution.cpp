/*
unsigned integer, 32 bits
0000 0010 1001 0100 0001 1110 1001 1100
0011 1001 0111 1000 0010 1001 0100 0000
digit by digit
rightmost digit: n & 1
n = n >> 1
*/
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, unordered_map<uint32_t, uint32_t>& cache) {
        if (cache.count(byte)) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }
    
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t power = 24;
        unordered_map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};