#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //init
    string sample;
    cin >>sample;
    stack<char> stack_;

    int laser=0, bar = 0, cut = 0;
    char temp_storage = '(';
    char c;

    for(auto c: sample)
    {
        cout <<"now c is: " << c <<'\n';
        if(c == '(')
        {
            stack_.push('(');
            temp_storage = '(';
        }
        else
        {
            if(temp_storage == '(')
            {
                stack_.pop();
                cut += stack_.size();
                cout <<"appending "<< stack_.size()<<" to cut"<<'\n';
            }
            else
            {
                stack_.pop();
                bar ++;
            }
            temp_storage = ')';
        }
    }
    for(int i=0; i<stack_.size();i++)
    {
        cout <<stack_.top();
        stack_.pop();
    }
    cout<<'\n'<<cut+bar<< '\n';
    return 0;
}
