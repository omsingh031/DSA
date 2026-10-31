class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        low, high = 0, len(numbers) - 1
        while low < high:
            s = numbers[low] + numbers[high]
            if s == target:
                return [low + 1, high + 1]
            elif s < target:
                low += 1
            else:
                high -= 1