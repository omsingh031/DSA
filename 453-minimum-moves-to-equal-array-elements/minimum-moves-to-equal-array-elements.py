class Solution:
    def minMoves(self, nums: list[int]) -> int:
        sum=0
        min_el=inf
        n=len(nums)
        for i in range(n):
            sum+=nums[i]
            min_el=min(min_el,nums[i])
        return sum-(n*min_el)    
        