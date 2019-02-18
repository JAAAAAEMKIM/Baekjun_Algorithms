#Baekjun 1181 Sorting Words
#retrieved from https://www.acmicpc.net/problem/1181
#by python 3.6

#define a function combining words with length
def makeLenDict(Lst):
    lendict = dict()
    for i in Lst:
        lendict.update({i: len(i)})
    return lendict

#make a list of input
a = []
N =int(input())
while N:
    word = input()
    a.append(word)
    N -= 1

#sort first by alphabetical order
a = sorted(a)
lendic = makeLenDict(a)

#sort second by length
lendic= sorted(lendic, key = lambda t: lendic[t])

#Output
for item in lendic:
    print(item)
