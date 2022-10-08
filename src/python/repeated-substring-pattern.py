class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # find abab in abababab
        t=s*2
        if t[1:-1].find(s)!=-1: return 1
        else: return 0

