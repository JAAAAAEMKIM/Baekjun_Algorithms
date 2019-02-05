from math import log2

def Star(n):
    if n == 1:
        result = [['  *   '],[' * *  '],['***** ']]
        return result
    else:
        blank_num = 3*2**(n-2)
        blank_height = 3*2**(n-2)
        result = []
        for i in range(1, blank_height+1):
            result.append([blank_num*" "+Star(n-1)[i-1][0]+blank_num*" "])
        for i in range(1, blank_height + 1):
            result.append([2*Star(n-1)[i-1][0]])
        return result

N = int(input(' '))

k = int(log2(N/3)) + 1

for j in Star(k):
    print(j[0])
