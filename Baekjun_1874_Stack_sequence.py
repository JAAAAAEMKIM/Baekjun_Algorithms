# Baekjun 1874 Stack Sequence
# retrieved from https://www.acmicpc.net/problem/1874
# in python 3.6

from sys import stdin
import stack         # Baekjun_10828_Stack.py

n = int(stdin.readline())
seq = []
stack_ = stack.Stack()

for j in range(n):
    num = int(stdin.readline())
    seq.append(num)
    result = []
    sign_list = []

k = 0
i = 1

# loop
while len(result) != n:

    if i < seq[k]:
        stack_.push(i)
        print('+', end = '   ')
        sign_list.append('+')
        print(stack_.stack, result, i, k+1,'th element', '  case 1')
    elif i == seq[k]:

        stack_.push(i)
        print('+', end='   ')
        sign_list.append('+')
        print(stack_.stack, result, i, k+1,'th element','  case 2')
        seq_val = stack_.pop()
        result.append(seq_val)
        print('-', end='   ')
        sign_list.append('-')
        print(stack_.stack, result, i, k+1,'th element')
        k += 1

    else: # i > seq[k]
        seq_val = stack_.pop()
        result.append(seq_val)
        print('-', end='   ')
        sign_list.append('-')
        print(stack_.stack, result, i, k+1,'th element', '  case 3')
        k += 1
        i -= 1
    i += 1
    # end of while


if result == seq:
    for i in sign_list: print(i)
else:
    print('NO')
