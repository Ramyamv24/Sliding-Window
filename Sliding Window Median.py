import heapq
from collections import defaultdict
from typing import List

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        small = []  # max-heap
        large = []  # min-heap
        delayed = defaultdict(int)
        small_size = large_size = 0

        def prune_small():
            while small and delayed[-small[0]] > 0:
                delayed[-small[0]] -= 1
                heapq.heappop(small)

        def prune_large():
            while large and delayed[large[0]] > 0:
                delayed[large[0]] -= 1
                heapq.heappop(large)

        def rebalance():
            nonlocal small_size, large_size
            if small_size > large_size + 1:
                val = -heapq.heappop(small)
                heapq.heappush(large, val)
                small_size -= 1
                large_size += 1
                prune_small()
            elif small_size < large_size:
                val = heapq.heappop(large)
                heapq.heappush(small, -val)
                large_size -= 1
                small_size += 1
                prune_large()

        result = []

        for i, num in enumerate(nums):
            if small and num <= -small[0]:
                heapq.heappush(small, -num)
                small_size += 1
            else:
                heapq.heappush(large, num)
                large_size += 1

            rebalance()

            if i >= k:
                out_num = nums[i - k]
                delayed[out_num] += 1

                if out_num <= -small[0]:
                    small_size -= 1
                    if out_num == -small[0]:
                        prune_small()
                else:
                    large_size -= 1
                    if large and out_num == large[0]:
                        prune_large()

                rebalance()

            if i >= k - 1:
                if k % 2 == 1:
                    result.append(float(-small[0]))
                else:
                    result.append((-small[0] + large[0]) / 2.0)

        return result


# Main Function
if __name__ == "__main__":
    nums = list(map(int, input("Enter array elements: ").split()))
    k = int(input("Enter window size: "))

    sol = Solution()
    ans = sol.medianSlidingWindow(nums, k)

    print(*ans)