def f(s, seen = ()) -> int:
    maximum = 0
    for i in range(1, len(s) + 1):
        candidate = s[:i]
        if candidate not in seen:
            maximum = max(maximum, 1 + f(s[i:], {candidate, *seen}))
    return maximum
    
class Solution:

    
    def maxUniqueSplit(self, s: str) -> int:
        return f(s, ())
    
