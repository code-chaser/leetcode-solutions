class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def f(nums,ds,flag):
            if len(ds) == len(nums):
                ans.append(ds.copy())
                return
            
            for i in range(len(nums)):
                if not flag[i]:
                    flag[i] = True
                    ds.append(nums[i])
                    f(nums,ds,flag)
                    ds.remove(nums[i])
                    flag[i] = False
        
        
        
        
        
        
        ans = []
        flag = [False]*len(nums)
        f(nums,[],flag)
        return ans
