from collections import Counter

class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        target = n // 4
        count = Counter(s)

        # If already balanced
        if all(count[c] == target for c in "QWER"):
            return 0

        left = 0
        result = n

        for right in range(n):
            count[s[right]] -= 1  # this char is now inside the window

            # While outside counts are all valid
            while left <= right and all(count[c] <= target for c in "QWER"):
                result = min(result, right - left + 1)
                count[s[left]] += 1  # put this char back outside
                left += 1

        return result


# Main Function
if __name__ == "__main__":
    obj = Solution()

    # Example input
    s = "WQWRQQQW"

    ans = obj.balancedString(s)

    print("Minimum length of substring to replace:", ans)