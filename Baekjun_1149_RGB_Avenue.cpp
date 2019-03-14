/*
 * Baekjun 1149 RGB Avenue
 * retrieved from https://www.acmicpc.net/problem/1149
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, G, B;
    int RGB[1000][3]; //RGB[i][0] = R; ~[1] = G; ~[2] = B;
    int D[1000][3];
    cin >> N;

// input
    for(int i=0; i<N; i++){
        cin >> R >> G >> B;
        RGB[i][0] = R;
        RGB[i][1] = G;
        RGB[i][2] = B;
    }
//initialize
    D[0][0] = RGB[0][0];
    D[0][1] = RGB[0][1];
    D[0][2] = RGB[0][2];
// Start DP operation
    for(int i=1; i<N; i++){
        D[i][0] = min(D[i-1][1], D[i-1][2]) + RGB[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + RGB[i][1];
        D[i][2] = min(D[i-1][1], D[i-1][0]) + RGB[i][2];
    }
    int res = min(D[N-1][0], D[N-1][1]);
    res = min(res, D[N-1][2]);
    cout << res;

    return 0;
}
