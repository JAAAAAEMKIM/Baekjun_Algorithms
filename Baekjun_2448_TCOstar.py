# Baekjun 2448 별 찍기-11
# retrieved from https://www.acmicpc.net/problem/2448
# optimized by Tail recursion in python 3.6

from math import log2
import time

def TCOstar(n, before):
    m = n + 2
    while True:
        if n == 1:
            return before  # before is a list
        else:
            k = m - n
            blank_num = 3 * 2 ** (k - 2)
            blank_height = 3 * 2 ** (k - 2)
            result = []
            for i in range(0, blank_height):
                result.append([blank_num * " " + before[i][0] + blank_num * " "])
            for i in range(0, blank_height):
                result.append([2 * before[i][0]])
            before = result
            n -= 1


N = int(input(' '))

start = time.time()

k = int(log2(N / 3)) + 1
firstar = [['  *   '],
           [' * *  '],
           ['***** ']]

for items in TCOstar(k, firstar):
    print(items[0])

end = time.time()
print("%d seconds taken" %(start - end))
