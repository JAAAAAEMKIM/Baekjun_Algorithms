# Baekjun 2675 repeating string
# retrieved from https://www.acmicpc.net/problem/2675
# in python 3.6


T = int(input())
while T:
    R, S = input().split(' ')
    for i in S:
        print(i*int(R), end='')
    print('')
    T -= 1
