class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        checking if a string is pallindrome or not
        firstly we need to trim spaces between string
        and traverse
        """
        word=str()
        for i in s:
            if i.isalnum():
                word+=(i.lower())
        
        return word==word[::-1]
