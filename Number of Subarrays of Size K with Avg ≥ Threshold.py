from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        tar = threshold * k
        win = 0
        c = 0

        for i in range(len(arr)):
            win += arr[i]

            if i >= k:
                win -= arr[i - k]

            if i >= k - 1 and win >= tar:
                c += 1

        return c


# Main Part
if __name__ == "__main__":
    arr = [2, 2, 2, 2, 5, 5, 5, 8]
    k = 3
    threshold = 4

    sol = Solution()
    result = sol.numOfSubarrays(arr, k, threshold)

    print("Number of valid subarrays:", result)