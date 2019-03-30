#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //init
    string str;
    list<char> L;

    cin >> str;
    for(auto s: str){
        L.insert(L.end(), s);
    }
    list<char>::iterator it1;


    int N; // number of operations
    cin >> N;
    int cursor = str.length();
    string temp;

    //operation
    it1 = L.end();
    while(N--)
    {
        getline(cin, temp);     //read line with blank
        while(temp.length()==0)
            getline(cin, temp);
        switch(temp[0])
        {
        case 'L':
            if(cursor==0) continue;
            cursor--;
            it1=prev(it1);
            continue;
        case 'D':
            if(cursor == L.size()) continue;
            cursor++;
            it1 = next(it1);
            continue;
        case 'B':
            if (cursor==0) continue;
            L.erase(prev(it1));
            cursor--;
            continue;
        case 'P':
            L.insert(it1, temp[2]);
            cursor++;
            continue;
        }
    }
    for(auto s: L){
        cout<<s;
        }

    return 0;
}
