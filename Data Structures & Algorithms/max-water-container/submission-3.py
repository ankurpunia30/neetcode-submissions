class Solution:
    def maxArea(self, heights: list[int]) -> int:
        max_ans = 0
        left, right = 0, len(heights) - 1

        while left < right:
            width = right - left
            if heights[left] < heights[right]:
                max_ans = max(max_ans, width * heights[left])
                left += 1
            else:
                max_ans = max(max_ans, width * heights[right])
                right -= 1

        return max_ans