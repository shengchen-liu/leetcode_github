class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # 1. build a dictinary
        counts = {}
        for i in nums:
            if i not in counts:
                counts[i] = 1
            else:
                counts[i] += 1
        
        # 2. sort
        sorted_counts = sorted(counts.items(), key=lambda kv: kv[1], reverse=True)
        
        result = []
        for j in range(k):
            result.append(sorted_counts[j][0])
        return result