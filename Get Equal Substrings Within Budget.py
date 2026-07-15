class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        left = 0
        cost_sum = 0
        result = 0

        for right in range(len(s)):
            cost_sum += abs(ord(s[right]) - ord(t[right]))

            while cost_sum > maxCost:
                cost_sum -= abs(ord(s[left]) - ord(t[left]))
                left += 1

            result = max(result, right - left + 1)

        return result


# Main Part
if __name__ == "__main__":
    s = input("Enter first string (s): ")
    t = input("Enter second string (t): ")
    maxCost = int(input("Enter maxCost: "))

    obj = Solution()
    ans = obj.equalSubstring(s, t, maxCost)

    print("Maximum length of equal substring:", ans)