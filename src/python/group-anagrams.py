#https://leetcode.com/problems/group-anagrams/
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d={}
        for words in strs:
            key=tuple(sorted(words))
            d[key]=d.get(key,[])+[words]
        return d.values()