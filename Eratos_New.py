import time
start_time = time.time()

def Eratos_New(M, N):
    #init
    Initial_list = []
    Sieve =[]
    Primes = []
    for i in range(M, N + 1):
        Initial_list.append(i)
        Sieve.append('W')

    #Sieving
    for i in range (2, N + 1):
        key = i
        for j in range(M, N + 1):
            if Sieve[j-M] == 'B':
                pass
            elif j%key == 0 and Sieve[j-M] == 'W':
                Sieve[j-M] = 'G'
            elif j%key == 0 and Sieve[j-M] == 'G':
                Sieve[j-M] = 'B'
            else: pass

    #making Primes
    for i in range(0, len(Sieve)):
        if Sieve[i] == 'G':
            Primes.append(Initial_list[i])
    return Primes

#Solution
M = int(input())
N = int(input())
Primes = Eratos_New(M, N)
result_list = []
for item in range(M, N+1):
    if item in Primes:
        result_list.append(item)
if result_list == []:
    print(-1)
else:
    Sum = sum(result_list)
    Min = result_list[0]

    print(Sum)
    print(Min)
print("--- %s seconds ---" %(time.time() - start_time))