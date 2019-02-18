# Baekjun 2747 fibonacci
# retrieved from https://www.acmicpc.net/problem/2747
# in python 3.6

# Using Tail Recurtion (TCO; Tail Call Optimization)


def TCOfibonacci(n, before, bbefore):
    while True:
        if n == 0:
            return 0

        elif n == 1:
            return bbefore

        elif n == 2:
            return before

        else:
            temp = bbefore
            bbefore = before
            before += temp
            n -= 1
