# 2227. Encrypt and Decrypt Strings
# https://leetcode.com/problems/encrypt-and-decrypt-strings/

class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.back = dict()
        self.keys = keys
        self.values = values
        self.dictionary = dictionary
        
        for i, key in enumerate(keys):
            self.back[key] = i
            
        self.ddict = Counter(self.encrypt(d) for d in self.dictionary)

    def encrypt(self, word1: str) -> str:
        return ''.join(self.values[self.back[i]] for i in word1)
    
    def decrypt(self, word2: str) -> int:
        return self.ddict[word2]

# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
