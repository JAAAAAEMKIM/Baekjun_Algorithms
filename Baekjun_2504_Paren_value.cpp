/*
 * Baekjun 2504 Parenthesis value solved by stack
 * retrieved from https://www.acmicpc.net/problem/2504
 * in C++ 14
 */
 
 
#include <bits/stdc++.h>
using namespace std;

// def paren-completeness-check function

int check_parenthesis(string s)
{
    stack<char> stack__;
    int num = 0;
    for(auto c:s)
    {
        if(c == '(' or c =='[')
           stack__.push(c);
        else
        {
            if(stack__.empty())
            {
                stack__.push('x');
                break;
            }
            if(c==')')
            {
                if(stack__.top() != '(')
                    break;
            }
            else    // c == ']'
            {
                if(stack__.top() != '[')
                    break;
            }
            stack__.pop();
        }
    }
    if(stack__.empty())
        return 1;
    else
        return 0;
}


// def value calculating function by recursion

int value_(string s, int rec)   // rec: checking recursion depth
{
    // Initialize
    stack<char> stack_;     // I used stack.
    int val_list[15];       // holds 2s and 3s.
    int ndx_list[15];       // holds the index.
    int i=0, j=0;           // to iteratively point the index.
    int result=0;
 
    // Operation 
    for(auto c: s)      // for loop
    {
        if(stack_.empty())  // if stack is empty
        {
            if(c =='(')                 // storing the index of the 
            {                           // beginning points of substrings, 
                stack_.push(c);         // and the multiplying values in order.
                ndx_list[j] = i;    
                val_list[j++] = 2;    // if '(' multiplying value will be 2
            }
            else if(c =='[')
            {
                stack_.push(c);
                ndx_list[j] = i;
                val_list[j++] = 3;    // if '[' multiplying value will be 3
            }
        }

        else        //if stack is not empty
        {
            if(c =='(')
            {
                stack_.push(c);
            }
            else if(c =='[')
            {
                stack_.push(c);
            }
            else if(c ==')')           // closing parens ')'
            {
                if (stack_.top()=='(') // check if it matches
                {
                    stack_.pop();
                }
                else
                    break;
            }
            else    // c == ']'        // closing parens ']'
            {
                if (stack_.top()=='[') // check if it matches
                {
                    stack_.pop();
                }
                else
                    break;
            }
        }
        i++;    // iterator ++
    }  // End of for loop
 
    // Starting calculation
    ndx_list[j] =i;             // Adding the last index
    for(int k = 0; k<j; k++)    // for loop for j times; j is the number of substructures.
    {                           // (We increased 'j' when we found the cleavage.)
        int pre = ndx_list[k];
        int idx = ndx_list[k+1];
        int val = val_list[k];
        string sub;
        sub = s.substr(pre+1, idx-pre-2);
        
        // Conditioning
        if (sub.length() ==0)  // If minimum structure (cf. () or [])
        {
            result += val;     
        }
        else                   // Else recursively calculate the value.
        {
            result += val*value_(sub, ++rec);  
        }
    }
        return result;
} 
// End of function def.

// Main
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //setting

    //init
    string samp;
    cin >> samp;
    int R=0;

    //operation
    if(check_parenthesis(samp))    // If parenthesis is complete
    {
        R = value_(samp,0);        // Use function 'value_'.
        cout << R<<'\n';
    }
    else{cout <<0;}                // If parenthesis is NOT complete
    return 0;
} // End of solution
