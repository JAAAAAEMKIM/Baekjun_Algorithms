# Baekjun 2108 Statistics
# retrieved from https://www.acmicpc.net/problem/2108
# in python 3.6

# find Average, median, mode, range of given values.

#import numpy as np     //Can do without numpy


class Stats:
    def __init__(self, num, list):
        self.num = num
        self.list = sorted(list)

    def Avg(self):
        sum = 0
        for i in self.list:
            sum += i
        return round(sum/self.num)

    def Med(self):
        idx = int((self.num-1)/2)
        return self.list[idx]

    def Mode(self):
        keys = set(self.list)
        modedict = dict()
        for key in keys:
            modedict.update({key: 0})
        maxnum = 0
        for value in self.list:
            modedict[value] += 1
            if modedict[value] > maxnum:
                maxnum = modedict[value]

        temp = []
        for item in modedict.items():
            if item[1] == maxnum:
                temp.append(item[0])

        if len(temp) == 1:
            return temp[0]
        else:
            temp.remove(min(temp))
            return min(temp)
        
    def Rng(self):
        return self.list[-1] - self.list[0]


N = int(input(""))
A = []
for i in range(N):
    A.append(int(input('')))

StatOne = Stats(N, A)

print('Avg = ', StatOne.Avg(), '\nMedian = ', StatOne.Med(), '\nMode = ', StatOne.Mode(), '\nRange = ', StatOne.Rng())
