class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)

        if n1 > n2:
            return False

        n = [0] * 26
        win = [0] * 26

        for ch in s1:
            n[ord(ch) - ord('a')] += 1

        for i in range(n2):
            win[ord(s2[i]) - ord('a')] += 1

            if i >= n1:
                win[ord(s2[i - n1]) - ord('a')] -= 1

            if win == n:
                return True

        return False


# Main Part
if __name__ == "__main__":
    s1 = input("Enter s1: ")
    s2 = input("Enter s2: ")

    sol = Solution()
    result = sol.checkInclusion(s1, s2)

    print(result)