class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans: list[list[int]] = []

        for i, target in enumerate(nums):
            # Since the array is sorted, no three positive numbers can sum to 0
            if target > 0:
                break
            # Skip duplicate anchor values
            if i > 0 and target == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1
            while left < right:
                total = target + nums[left] + nums[right]
                if total == 0:
                    ans.append([target, nums[left], nums[right]])
                    left += 1
                    right -= 1
                    # Skip duplicate left values so we don't emit repeated triplets
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                elif total > 0:
                    right -= 1
                else:
                    left += 1

        return ans