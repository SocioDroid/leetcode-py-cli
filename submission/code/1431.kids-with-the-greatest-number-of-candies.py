class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_item = max(candies)
        return [i + extraCandies >= max_item for i in candies]       