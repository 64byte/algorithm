class Solution:
    ans = 0

    def util(self, n: int, pos: int, vistied: List[bool]):
        if pos > n:
            self.ans += 1

        for x in range(1, n+1):
            if not vistied[x] and (pos % x == 0 or x % pos == 0):
                vistied[x] = True
                self.util(n, pos+1, vistied)
                vistied[x] = False

    def countArrangement(self, n: int) -> int:
        visited = [False for _ in range(0, n+1)]
        self.util(n, 1, visited)
        return self.ans
