/*
 * Baekjun 11726 2xn Tiling solved by DP
 * retrieved from https://www.acmicpc.net/problem/11726
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; // n < 1000
    cin >> n;

    int D[1000] = {};
    D[1] = 1;
    D[2] = 2;
    D[3] = 3;
    for(int i=4; i<=n; i++)
    {
        D[i] = (D[i-1]+D[i-2])%10007;
    }
    cout << D[n];


    return 0;
}
