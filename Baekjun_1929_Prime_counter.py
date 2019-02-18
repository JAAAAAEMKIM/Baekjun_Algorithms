


import math

def PrimeCounter(M, N):
    Init_list = []
    if M == 2:
        Init_list.append(2)
        for j in range(3, N + 1, 2):
            Init_list.append(j)
            rootj = int(math.sqrt(j))
            for i in range(3, rootj + 1,2):
                if j % i == 0:
                    Init_list.remove(j)
                    break
    elif M%2 == 0:
        for j in range(M+1, N + 1, 2):
            Init_list.append(j)
            rootj = int(math.sqrt(j))
            for i in range(3, rootj+1, 2):
                if j%i == 0:
                    Init_list.remove(j)
                    break
    elif M == 1:
        Init_list.append(2)
        for j in range(3, N + 1, 2):
            Init_list.append(j)
            rootj = int(math.sqrt(j))
            for i in range(3, rootj + 1,2):
                if j % i == 0:
                    Init_list.remove(j)
                    break

    else:
        for j in range(M, N + 1, 2):
            Init_list.append(j)
            rootj = int(math.sqrt(j))
            for i in range(3, rootj + 1,2):
                if j % i == 0:
                    Init_list.remove(j)
                    break
    return Init_list

M, N = map(int, input("").split(' '))
results = PrimeCounter(M, N)
for i in results:
    print(i)
