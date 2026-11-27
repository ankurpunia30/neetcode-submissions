
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_freq = [0] * 26
        s2_freq = [0] * 26

        n = len(s1)

        # Build frequency arrays for s1 and first window
        for i in range(n):
            s1_freq[ord(s1[i]) - ord('a')] += 1
            s2_freq[ord(s2[i]) - ord('a')] += 1

        if s1_freq == s2_freq:
            return True

        # Slide the fixed-size window
        for right in range(n, len(s2)):
            # Add incoming character
            s2_freq[ord(s2[right]) - ord('a')] += 1

            # Remove outgoing character
            left = right - n
            s2_freq[ord(s2[left]) - ord('a')] -= 1

            if s1_freq == s2_freq:
                return True

        return False
