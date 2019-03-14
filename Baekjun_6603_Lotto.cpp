/*
 * Baekjun 6603 Lotto solved by back tracking
 * retrieved from https://www.acmicpc.net/problem/6603
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int isused[49]={0};
int arr[6]={0};
int lrg =0;

void func(int* num, int n, int k)
{
    //base condition
    if(k==6)              // The output array is  fully filled.
    {
        for(int i=0; i<6; i++)
            cout << arr[i]<<' ';
        cout<<'\n';
        cout.clear();
    }

    //recursion
    for(int j=0; j<n; j++)
    {
        if(isused[j])continue;  // used in array 
        if(lrg<num[j]){         // if new num is larger
            lrg = num[j];
            isused[j]=1;
            arr[k] = num[j];
            func(num, n, k+1);
            isused[j]=0;
            arr[k] = 0;
            lrg = arr[k-1];     // Turning back lrg as before.
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int input;
    while(1){
        cin >> n;
        if(n==0) break;       // Break if 0;
        
        int num[n];
        for(int i=0; i<n; i++)
        {
            cin>>num[i];
        }
        func(num, n, 0);
        cout << '\n';
    }
    return 0;
}
