class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mappings = {}

        for i in strs:
            temp = [0] * 26

            for j in i:
                temp[ord(j) - ord('a')] += 1

            key = tuple(temp)

            if key not in mappings:
                mappings[key] = []

            mappings[key].append(i)

        return list(mappings.values())