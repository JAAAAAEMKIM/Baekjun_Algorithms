/*
 * Baekjun 1182 partial sequence
 * retrieved from https://www.acmicpc.net/problem/1182
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, res=0;
    cin >>n >>s;
    int num[n];
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    for(int i=1; i<pow(2,n); i++){
        int sum =0;
        int tmp=i;
        for(int j=0; j<n; j++){
            int Q = tmp/2;
            int R = tmp%2;
            tmp = Q;
            if(R==1){
                sum+=num[j];
            }
        }
        //cout << i <<' '<<sum<<'\n';
        if(sum == s)
            res++;
        //cout << res<<'\n';
    }
    cout << res;


    return 0;
}
