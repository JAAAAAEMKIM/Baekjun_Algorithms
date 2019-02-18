# Baekjun 1003 fibonacci by dynamic programming
# retrieved from https://www.acmicpc.net/problem/10828
# in python 3.6


import sys

fib_list = []


def fibonacci(n, before, bbefore, dp_list):
    i = n

    while True:
        key = n - i
        if i == 0:
            return bbefore

        elif i == 1:
            return before

        else:
            temp = bbefore
            bbefore = before
            before = bbefore + temp
            dp_list.append([key+1, before])
            i -= 1


N = sys.stdin.readline()
N = int(N)

while N:
    zero_one_ = [[0, 0], ]
    case = int(sys.stdin.readline())
    fibonacci(case+1, 0, 1, zero_one_)
    N -= 1

    if case >= 2:
        print(zero_one_[case-1][1], zero_one_[case][1])
    elif case == 0:
        print(1, 0)
    else:
        print(0, 1)

