/*
 * Baekjun 1074 Z solved by recursion
 * retrieved from https://www.acmicpc.net/problem/2178
 * in C++ 14
 * FAILED
 */


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second


int calculator(int N, int r, int c, int val)
{
    if(N!=0){
        int n = pow(2, N);
        if(0<=c && c<pow(2,N-1) && 0<=r && r<pow(2,N-1)){
            //val += 0;
            return calculator(N-1, r, c, val);
        }
        else if(pow(2,N-1)<=c && c<pow(2,N) && 0<=r && r<pow(2,N-1)){
            val += n*n/4;
            return calculator(N-1, r, c-n/2, val);
        }
        else if(0<=c&& c<pow(2,N-1) && pow(2,N-1)<=r && r<pow(2,N)){
            val += n*n/2;
            return calculator(N-1, r-n/2, c, val);
        }
        else{ //pow(2,N-1)<=c && c<pow(2,N) && pow(2,N-1)<=r && r<pow(2,N)
            val += 3*n*n/4;
            return calculator(N-1, r-n/2, c-n/2, val);
        }
    }
    if (N==0)
    {
        val += c+r;
    }
    return val;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    int N, r, c;
    cin >> N >> r >> c ;
    int n = pow(2, N);
    int mat[n][n];
    for(int i = 0; i<n; i++){
        for (int j=0; j<n; j++)
            mat[i][j] =calculator(N, i, j, 0);
    }
    cout <<mat[r][c];
    return 0;
}
