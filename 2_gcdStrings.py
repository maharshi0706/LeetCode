def gcdOfStrings(str1: str, str2: str) -> str:
    if str1 + str2 != str2 + str1:
        return ""
    if len(str1) == len(str2):
        return str1
    if len(str1) > len(str2):
        return gcdOfStrings(str1[len(str2):],str2)
    return gcdOfStrings(str1,str2[len(str1):])

s1 = 'ABCDEF'
s2 = 'AB'
output = gcdOfStrings(s1,s2)
print(f'1:{s1},\n2:{s2} -> \noutput:{output}')
    