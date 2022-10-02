class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def solve(ind,ds,k,su,n,it):
            if ind == k:
                if su == n:
                    ans.append(ds.copy())
                return
            for i in range(it,9+1):
                if i not in ds:
                    
                    ds.append(i)
                    
                    solve(ind+1,ds,k,su+i,n,i+1)
                    ds.remove(i)
        ans = []
        solve(0,[],k,0,n,1)
        return ans
