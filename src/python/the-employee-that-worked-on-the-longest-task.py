# 2432. The Employee That Worked on the Longest Task
# https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        longest = logs[0][1]
        result = logs[0][0]
        for i in range(1, len(logs)):
            duration = logs[i][1] - logs[i - 1][1]
            if duration > longest or (duration == longest and logs[i][0] < result):
                longest = logs[i][1] - logs[i - 1][1]
                result = logs[i][0]
                
        return result
    