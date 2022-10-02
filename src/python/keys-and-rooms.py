# 841. Keys and Rooms
# https://leetcode.com/problems/keys-and-rooms/

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = set()
        
        def dfs(u):
            visited.add(u)
            for v in rooms[u]:
                if v not in visited:
                    dfs(v)
        dfs(0)
        return len(visited) == len(rooms)
    