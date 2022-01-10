class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        ans = []

        dic = Counter(arr1)

        for x in arr2:
            if x in dic:
                for _ in range(0, dic[x]):
                    ans.append(x)
                del dic[x]

        for k, v in sorted(dic.items()):
            if v != 0:
                for _ in range(0, v):
                    ans.append(k)

        return ans
