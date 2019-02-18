# Baekjun 11050 Binomial Coefficient
# retrieved from https://www.acmicpc.net/problem/11050
# in python 3.6


def binomial_coef(N, K):
    # Making list of coefficients
    combination = [[1], [1, 1]]
    i = N

    # loop
    while True:
        key = N - i
        if N == 0:
            return 1

        elif N == 1:
            return 1

        elif K == 0:
            return 1

        elif K == N:
            return 1

        else:
            combination.append([1])
            for j in range(key+1):
                left = combination[key + 1][j]        # n-1Ck-1
                right = combination[key + 1][j+1]     # n-1Ck
                combination[-1].append(left + right)  # nCk = n-1Ck-1 + n-1Ck
            combination[-1].append(1)                 # append the value to the existing list
        i -= 1

        # break condition
        if key == N - 2:
            break
    
    return combination[N][K]

# problem solving
N, K = map(int, input('').split(' '))
result = binomial_coef(N, K)
print('result is : ', result)
