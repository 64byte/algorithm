class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ns = sorted(nums)
        
        dic = {}
        
        i = 0
        for x in ns:
            if x not in dic:
                dic[x] = i
            
            i += 1            
                                
        ans = []
        for x in nums:
            ans.append(dic[x])
            
        return ans
        
