# Baekjun 1978 Get Primes
# retrieved from https://www.acmicpc.net/problem/1978
# in python 3.6


"""
Eratosthenes
주어진 리스트의 사이즈에 맞는 체 생성
 -입력 리스트의 가장 큰 값을 찾음
 -그 값 이하인 모든 소수들을 찾음
 -그 소수들로 구성된 리스트 만듬

체에 있는 요소와 입력리스트의 값비교

겹치는 요소들의 개수를 출력
"""


import time
start_time = time.time()   #Checking start time

def Eratos(N):
    #init
    Initial_list = []
    Sieve =[]
    Primes = []
    for i in range(1, N + 1):
        Initial_list.append(i)
        Sieve.append('W')

    #Sieving by coloring
    for i in range (2, N + 1):
        key = i
        for j in range(2, N + 1):
            if Sieve[j-1] == 'B':
                pass
            elif j%key == 0 and Sieve[j-1] == 'W':
                Sieve[j-1] = 'G'
            elif j%key == 0 and Sieve[j-1] == 'G':
                Sieve[j-1] = 'B'
            else: pass

    #making Primes
    for i in range(0, len(Sieve)):
        if Sieve[i] == 'G':
            Primes.append(Initial_list[i])
    return Primes

#Solution
N = int(input())
input_list = list(map(int, input().split( )))
print(input_list)
count = 0
Primes = Eratos(input_list[-1])
for item in input_list:
    if item in Primes:
        count += 1
print(count)
print("--- %s seconds ---" %(time.time() - start_time))
