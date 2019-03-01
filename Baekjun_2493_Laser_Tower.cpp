/*
 * Baekjun 2493 Laser tower
 * retrieved from https://www.acmicpc.net/problem/2493
 * in C++ 14
 */


#include <iostream>
#include <stdlib.h>


using namespace std;

int main()
{
    //init
    int N, num, i=0, j, lgt=0, lgt_idx = 0, sml= 100000000;
    int tower_list[500000];         // to store tower heights
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)      // for loop
    {
        scanf("%d", &num);

        tower_list[i]= num;
        if(lgt<num)                     // if larger than the largest value
        {                               // laser cannot be reached to any other tower.
            printf("0 ");
            lgt = num;
            lgt_idx = i;                // initialize the index of the largest value
            if(i==0)
            {
                sml = num;              // initialize the smallest value
            }
        }
        else if(sml>num)                // if smaller than the smallest
        {                               // index should be the one right before this new tower.
            printf("%d ", i);
            sml = num;
        }
        else // lgt > num
        {
            for(j = i; j>lgt_idx; j--)          //for loop from i to the largest
            {
                if (tower_list[j-1] > num)      // if the very first value larger than num is found
                {
                    //receive_index[i]= j-1;
                    printf("%d ", j);
                    break;
                }
            }   //end of inner for loop
        }
    }           //end of outer for loop
    return 0;
}
