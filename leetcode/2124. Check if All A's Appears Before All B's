class Solution:
    def checkString(self, s: str) -> bool:
        a = False
        b = False

        for ch in s:
            if ch == 'a':
                if b is True:
                    return False

                a = True
            elif ch == 'b':
                b = True

        return a or b
