
import re
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        res = re.search(needle, haystack)
        if res:
            return res.span()[0]
        return -1