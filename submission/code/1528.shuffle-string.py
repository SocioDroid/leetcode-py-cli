class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ls = [''] * len(indices)
        for i in range(len(ls)):
            ls[indices[i]] = s[i]
        return ''.join(ls)