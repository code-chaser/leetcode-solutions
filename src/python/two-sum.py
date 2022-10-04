#https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums, target):
        for i in range(len(nums)):
            try:
                diffindex = nums.index(target - nums[i], i + 1)
            except ValueError:
                continue
            if diffindex > i:
                return {i, diffindex}