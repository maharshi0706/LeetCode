def extraCandies(kids,extra):
    booleanHighestList = []
    maxCandies = max(kids)
    for i in range(len(kids)):
        checkCandies = kids[i] + extra
        booleanHighestList.append(checkCandies >= maxCandies)
    return booleanHighestList

kidsArray = [12,1,12]
extra = 10
output = extraCandies(kidsArray,extra)
print(output)
# ANOTHER SOLUTION
# for j in range(len(kids)):
#     if checkCandies >= kids[j]:
#         highest = True
#     else:
#         highest = False
#         break
    
# booleanHighestList.append(highest)
