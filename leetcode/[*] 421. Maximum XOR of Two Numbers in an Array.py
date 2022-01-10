class Solution:
    def findMaximumXOR(self, nums):
        ans, mask = 0, 0
        for i in range(31, -1, -1):
            can_ans = ans | 1 << i
            mask = mask | 1 << i

            bits = set()

            for n in nums:
                bits.add(mask & n)

            for b in bits:
                if b ^ can_ans in bits:
                    ans = can_ans
                    break

        return ans
