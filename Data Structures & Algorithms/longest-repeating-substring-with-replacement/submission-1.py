class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        left = 0
        max_freq = 0
        max_length = 0

        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1

            # Maximum frequency of a character
            max_freq = max(max_freq, freq[s[right]])

            # Shrink window if replacements exceed k
            window_length = right - left + 1

            if window_length - max_freq > k:
                freq[s[left]] -= 1
                left += 1

            # Update maximum valid window length
            max_length = max(max_length, right - left + 1)

        return max_length