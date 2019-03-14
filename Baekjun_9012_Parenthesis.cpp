/*
 * Baekjun 9012 Parenthesis
 * retrieved from https://www.acmicpc.net/problem/9012
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
    int N, i;
    cin >> N;
    string sample;


    while(N--)
    {
        stack<char> stack_;
        cin >> sample;
        
        // check whether it pairs.
        for(i = 0; i < sample.length(); i++) 
        {
            if (sample[i] =='(')
            {
                stack_.push(1);
            }
            else if(stack_.empty())
            {
                break;
            }
            else
            {
                stack_.pop();
            }
        }
        if (i==(int)sample.length() && stack_.empty())
            // if i itered to the end and the stack is empty
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }
    return 0;
}
