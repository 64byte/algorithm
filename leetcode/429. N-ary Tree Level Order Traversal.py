"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

from collections import deque

class Solution:    
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = []
        
        q = deque();
        
        q.appendleft([root, 0])
        
        while q:
            v, level = q.pop()
            
            if len(ans) <= level:
                ans.append([])
                        
            ans[level].append(v.val)
                    
            for ch in v.children:
                q.appendleft([ch, level+1])
            
            
        return ans
            
