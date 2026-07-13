from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n, m = len(s), len(p)

        if m > n:
            return []

        need = [0] * 26
        window = [0] * 26

        for ch in p:
            need[ord(ch) - ord('a')] += 1

        result = []

        for i in range(n):
            window[ord(s[i]) - ord('a')] += 1

            if i >= m:
                window[ord(s[i - m]) - ord('a')] -= 1

            if i >= m - 1 and window == need:
                result.append(i - m + 1)

        return result


# Main Part
if __name__ == "__main__":
    s = input("Enter string s: ")
    p = input("Enter string p: ")

    sol = Solution()
    ans = sol.findAnagrams(s, p)

    print("Starting indices of anagrams:", ans)