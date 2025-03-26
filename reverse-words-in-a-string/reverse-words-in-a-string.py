class Solution:
    def reverseWords(self, s: str) -> str:
        sl = s.strip().split()
        return " ".join(sl[::-1])
