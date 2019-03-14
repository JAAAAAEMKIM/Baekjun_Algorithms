/*
 * Baekjun 2309 7 Dwarfs
 * retrieved from https://www.acmicpc.net/problem/2309
 * in C++ 14
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //init
    int num_list[9];
    int res_list[2];
    int sum=0, j;
    for(int i=0; i<9; i++)
    {
        cin >> num_list[i];
        sum += num_list[i];
    }

    //operation
    int key_val = sum - 100;            // when the sum of two dwarfs' height
    for(int i=0; i<8; i++)              // is total sum -100, the sum of the
    {                                   // heights of the others are 100.
        for(j=i+1; j<9; j++)            // so check for all combinations.
        {
            if(key_val == num_list[i] + num_list[j])
            {
                res_list[0] = i;
                res_list[1] = j;
                break;
            }
        }
    }
    //deletion
    num_list[res_list[0]] = 0; 
    num_list[res_list[1]] = 0;

    //sorting (I could use sort function)
    for(int i=0; i<8; i++)
    {
        for(int k=0; k<8; k++)
        {
            if (num_list[k]> num_list[k+1])
            {
                int temp = num_list[k+1];
                num_list[k+1] = num_list[k];
                num_list[k] = temp;
            }
        }
    }

    //output
    for(int i = 2; i<9; i++)
    {
        cout << num_list[i] <<'\n';
    }

    return 0;
}
