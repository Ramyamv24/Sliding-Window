from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        zero_count = 0
        result = 0

        for right in range(len(nums)):
            if nums[right] == 0:
                zero_count += 1

            while zero_count > k:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

            result = max(result, right - left + 1)

        return result


# Main Part
if __name__ == "__main__":
    nums = list(map(int, input("Enter binary array (space-separated): ").split()))
    k = int(input("Enter the value of k: "))

    obj = Solution()
    ans = obj.longestOnes(nums, k)

    print("Longest consecutive 1s after flipping at most k zeros:", ans)