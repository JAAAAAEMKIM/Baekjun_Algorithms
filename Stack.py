
"""
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
"""

import sys


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, n):
        self.stack.append(n)

    def pop(self):
        try:
            val = self.stack[-1]
            self.stack.pop(-1)
            return val
        except IndexError:
            return -1

    def size(self):
        val = len(self.stack)
        return val

    def empty(self):
        if len(self.stack):
            return 0
        else:
            return 1

    def top(self):
        try:
            val = self.stack[-1]
            return val
        except IndexError:
            return -1


# Baekjun 10828 Stack
"""
N = int(input(''))
NewStack = Stack()

for i in range(0, N):
    line = sys.stdin.readline()

    if ' ' in line:
        pushVal = int(line.split(' ')[1])
        NewStack.push(pushVal)
        continue

    elif 'top' in line:
        print(NewStack.top())
        continue

    elif 'pop' in line:
        pop_val = NewStack.pop()
        print(pop_val)
        continue

    elif 'size' in line:
        print(NewStack.size())
        continue

    else:
        print(NewStack.empty())
        continue
"""


