class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        low=0
        high=len(numbers)-1
        while(low<=high):
            sum=numbers[low]+numbers[high]
            if (sum>target):
                high=high-1
            elif(sum<target):
                low=low+1
            else:
                return [low+1,high+1]
        return[low+1,high+1]              


        