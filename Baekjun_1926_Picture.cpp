/*
 * Baekjun 1926 Picture solved by BFS
 * retrieved from https://www.acmicpc.net/problem/1926
 * in C++ 14
 * referred to <https://blog.encrypted.gg/729?category=773649> for practice
 */

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int board[502][502];  // don't need to initialize
bool visited[502][502];
int dx[4] = {1,0,-1,0}; // L R
int dy[4] = {0,1,0,-1}; //  U D


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //setting

    //init
    int n, m;
    cin >>n >>m;
    for(int i=0; i<n; i++)      // x axis, n times
    {
        for(int j=0; j<m; j++)  // y axis, m times
        {
            cin >>board[i][j];  // Input values to the board in a given order

        }
    }
    int Max = 0;        // Max size of a picture
    int num = 0;        // # of pictures

    //operation
    for(int i=0; i<n; i++)      // x axis, n times
    {
        for(int j=0; j<m; j++)  // y axis, m times
        {
            if(board[i][j] == 0 or visited[i][j])
            // 0 is false color
            // we don't go to the visited place again.
            continue;
            /* after the previous checking step,
               we finally found unvisited, true colored nod.
               Keep going below. */
            num++;
            queue<pair<int,int>> Q;
            /* Make a queue of the element of which is a pair,
               again the element of which are two integers. */
            visited[i][j] = 1;  // Mark the node which we are now at as "visited".
            Q.push({i,j});      // {i,j} is a pair data type.
            int area = 0;

            // while loop
            while(!Q.empty())
            {
                area++;
                auto cur = Q.front();   // "Why auto?" :
                Q.pop();                // cuz we don't need to specify the data type.
                for(int dir = 0; dir < 4; dir++)    // dir: direction
                {
                    int nx = cur.X + dx[dir];       // cur: current Q front
                    int ny = cur.Y + dy[dir];       // .X, .Y: Each means "first", "second"
                                                    // of the data type "pair".
                /*  for loop to check 4 directions(L U R D)
                    cur.X and cur.Y indicates current location.
                    nx and ny shows absolute coordinate to check,
                    when dx and dy shows relative direction

                    for example,
                    if dir ==0:
                        nx = cur.X + 1
                        ny = cur.Y + 0
                        ==> checking right field

                    similarly,
                    if dir ==1:
                        nx = cur.X + 0
                        ny = cur.Y + 1
                        ==> checking field below current
                            (higher Y value -> lower location)
                */
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m)
                        continue;
                    // check if out-of-range
                    if(visited[nx][ny] or board[nx][ny] != 1)
                        continue;
                    // check if already visited or false color node.
                    // after checking every scenarios
                    // finally discovered unexplored node.
                    visited[nx][ny] = 1;      // indicate to have been "visited"
                    Q.push({nx,ny});
                }   // end of for loop
            }       // end of while loop and BFS for one node
            Max = max(Max, area);   // check max size after an iter.
            // max: STL::max(a,b)
        }
    }
    cout <<num <<'\n'<<Max;
    return 0;
}
