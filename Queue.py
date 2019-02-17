# Baekjun 10845 Queue
# retrieved from https://www.acmicpc.net/problem/10845
# in python 3.6

"""
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
"""


class Queue:
    def __init__(self):
        self.queue = []

    def push(self, n):
        self.queue.append(n)

    def pop(self):
        try:
            pop_val = self.queue.pop(0)
            return pop_val
        except IndexError:
            return -1

    def size(self):
        size_val = len(self.queue)
        return size_val

    def empty(self):
        if self.queue:
            return 0
        else: return 1

    def front(self):
        try:
            front_val = self.queue[0]
            return front_val
        except IndexError:
            return -1

    def back(self):
        try:
            back_val = self.queue[-1]
            return back_val
        except IndexError:
            return -1


# Main here

import sys

N = int(input(''))
NewQ = Queue()

for i in range(0, N):
    line = sys.stdin.readline()
    if ' ' in line:
        pushVal = int(line.split(' ')[1])
        NewQ.push(pushVal)
        continue

    elif 'front' in line:
        print(NewQ.front())
        continue

    elif 'back' in line:
        print(NewQ.back())
        continue

    elif 'pop' in line:
        pop_val = NewQ.pop()
        print(pop_val)
        continue

    elif 'size' in line:
        print(NewQ.size())
        continue

    else:
        print(NewQ.empty())
        continue

