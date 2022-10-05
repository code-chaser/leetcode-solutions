 def letterCasePermutation(self, S: str) -> List[str]:
        ans = [""]
        for s in S:
            if s.isdigit():
                ans = [c+s for c in ans]
            else:
                tmp1 = [c+s.lower() for c in ans]
                tmp2 = [c+s.upper() for c in ans]
                ans = tmp1 + tmp2
        return ans
