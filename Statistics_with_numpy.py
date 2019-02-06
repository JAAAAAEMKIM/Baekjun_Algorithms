#Baekjun 2108 Statistics
#find Average, median, mode, range of given values.
#retrieved from https://www.acmicpc.net/problem/2108

import numpy as np


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
        rows = len(keys)
        Modearray = np.empty((rows, 2))
        i = 0
        for value in keys:
            Modearray[i] = [value, self.list.count(value)]
            i += 1

        Howmany = list(Modearray[0:rows, 1])
        Maxnum = max(Howmany)

        temp = []
        if Howmany.count(Maxnum) != 1:
            for i in range(len(Howmany)):
                if Howmany[i] == Maxnum:
                    temp.append(Modearray[0:rows, 0][i])
                    temp = sorted(temp)
            return int(temp[1])
        else:
            idx = Howmany.index(Maxnum)
            return Modearray[0:rows, 0][idx]

    def Rng(self):
        return self.list[-1] - self.list[0]


N = int(input(""))
A = []
for i in range(N):
    A.append(int(input('')))

StatOne = Stats(N, A)

print('Avg = ', StatOne.Avg(), '\nMedian = ', StatOne.Med(), '\nMode = ', StatOne.Mode(), '\nRange = ', StatOne.Rng())
