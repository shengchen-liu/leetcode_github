/*
    [-1,0,3,5,9,12]
start = 0
incre = 1
end = start + incre = 1
mid = start + (end - start)/2 = 1

1. incre = 1
if a[end] == target:
    return end
else if a[end] < target:
    start = end
    incre = incre *2
    end = end + incre
else if a[end] > target:
    binary search
    
2. Binary search

*/

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start = 0;
        int end = 1;
        while(reader.get(end) <= target){
            if (reader.get(end) == target){
                return end;
            }
            start = end;
            // if it is greater than high index element then copy high index in low index and double the high index.
            end *= 2; //
        }
        return binary_search(start, end, reader, target);
        
    }
    
    public: int binary_search(int start, int end, const ArrayReader& reader, int target){
        while(start + 1 < end){
            int mid = start + (end - start)/2;
            if (reader.get(mid) == target){
                start = mid;
            }
            else if (reader.get(mid) < target){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        if (reader.get(start) == target){
            return start;
        }
        else if(reader.get(end) == target){
            return end;
        }
        else{
            return -1;
        }
    }
};