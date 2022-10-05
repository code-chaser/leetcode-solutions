#https://leetcode.com/problems/defanging-an-ip-address/
#By KrishGaur1354

lass Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".", "[.]")
