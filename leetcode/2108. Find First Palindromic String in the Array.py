class Solution:
    def isPal(self, s: str) -> bool:
        st = 0
        ed = len(s)-1
        for i in range(0, len(s)//2):
            if s[st] != s[ed]:
                return False
            st += 1
            ed -= 1

        return True

    def firstPalindrome(self, words: List[str]) -> str:
        for w in words:
            if self.isPal(w):
                return w

        return ""
