
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        len_s = len(s)
        len_t = len(t)

        if len_t > len_s:
            return ""

        # Build required character frequencies
        mapping_t = {}
        for char in t:
            mapping_t[char] = mapping_t.get(char, 0) + 1

        mapping_s = {}

        left = 0
        formed = 0
        required = len(mapping_t)

        min_len = float('inf')
        start = 0

        for right in range(len_s):

            # Expand window
            char = s[right]

            if char in mapping_t:
                mapping_s[char] = mapping_s.get(char, 0) + 1

                if mapping_s[char] == mapping_t[char]:
                    formed += 1

            # Shrink window while valid
            while formed == required:

                # Update minimum window
                window_len = right - left + 1

                if window_len < min_len:
                    min_len = window_len
                    start = left

                # Remove leftmost character
                left_char = s[left]

                if left_char in mapping_t:

                    if mapping_s[left_char] == mapping_t[left_char]:
                        formed -= 1

                    mapping_s[left_char] -= 1

                left += 1

        if min_len == float('inf'):
            return ""

        return s[start:start + min_len]
