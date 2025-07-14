from itertools import zip_longest


def mergeAlternately(word1,word2):
    str = ''
    for i,j in zip(word1,word2):
        str += i + j
    str += word1[len(word2):] + word2[len(word1):]
    # return ''.join([i+j for i,j in zip_longest(word1,word2,fillvalue='')])
    return str

word1 = 'abc'
word2 = 'xyzf'
output = mergeAlternately(word1,word2)
print(output)