class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k:
            return 0

        # Count frequency of each character
        count = {}
        for ch in s:
            count[ch] = count.get(ch, 0) + 1

        for ch in count:
            if count[ch] < k:
                # Split on the invalid character and recurse
                return max(self.longestSubstring(piece, k) for piece in s.split(ch))

        # Every character appears at least k times
        return len(s)



if __name__ == "__main__":
    s = "aaabb"
    k = 3

    sol = Solution()
    result = sol.longestSubstring(s, k)

    print("Length of the longest substring:", result)