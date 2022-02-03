class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        nums = sorted(nums)

        ans = []

        already = False
        for i in range(0, len(nums)):
            if nums[i-1] == nums[i]:
                already = True
            else:
                if already is False:
                    ans.append(nums[i-1])

                already = False

        return ans
