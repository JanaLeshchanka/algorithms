#include <iostream>
#include <stack>
#include <deque>

using namespace std;

typedef pair<int, int> place;

deque<place> deadends;
int* outs;
int n, m, k;

bool isOut(place c)
{
    if(c.first == n)
        for(int i = 1; i <= k; i++)
        {
            if(c.second == outs[i])
                return true;
        }
    return false;
}

bool isDeadend(place p)
{
    for(int i = 0; i < deadends.size(); i++)
    {
        if(p == deadends.at(i))
            return true;
    }
    return false;
}

bool isDeadendFromRight(int x, int y, int** maze, int i)
{
    return maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromLeft(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromUp(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromDown(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromRightUp(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromRightDown(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromLeftUp(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x + 1][y + 1] != i + 1 && maze[x + 1][y + 1] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

bool isDeadendFromLeftDown(int x, int y, int** maze, int i)
{
    return maze[x][y - 1] != i + 1 && maze[x][y - 1] != 0 &&
           maze[x + 1][y - 1] != i + 1 && maze[x + 1][y - 1] != 0 &&
           maze[x + 1][y] != i + 1 && maze[x + 1][y] != 0 &&
           maze[x][y + 1] != i + 1 && maze[x][y + 1] != 0 &&
           maze[x - 1][y + 1] != i + 1 && maze[x - 1][y + 1] != 0 &&
           maze[x - 1][y] != i + 1 && maze[x - 1][y] != 0 &&
           maze[x - 1][y - 1] != i + 1 && maze[x - 1][y - 1] != 0 &&
           !isOut(make_pair(x, y));
}

void no_exit(stack<place> path, int** maze)
{
//    //////////////////////////////////////
    cout << "no exit. path:" << endl;
//    //////////////////////////////////////
    while(!path.empty())
    {
        int x = path.top().first;
        int y = path.top().second;
//        ///////////////////////////////////
        cout << x << " " << y << endl;
//        ///////////////////////////////////
        path.pop();
        maze[x][y] = 0;
    }
//    ///////////////////////////////
//    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//    ////////////////////////////////
}

int main() {
    freopen("labyrinth.in", "r", stdin);
    freopen("labyrinth.out", "w", stdout);
    cin >> n >> m >> k;
    int pathsCount = k;
    int* ins = new int[k + 1];
    for(int i = 1; i <= k; i++)
        cin >> ins[i];
    outs = new int[k + 1];
    for(int i = 1; i <= k; i++)
        cin >> outs[i];
    int** labyrinth = new int*[n + 2];
    for(int i = 0; i <= n + 1; i++)
    {
        labyrinth[i] = new int[m + 2];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> labyrinth[i][j];
    for(int i = 0; i <= m; i++)
    {
        labyrinth[0][i] = 1;
        labyrinth[n + 1][i] = 1;
    }
    for(int i = 0; i <= n; i++)
    {
        labyrinth[i][0] = 1;
        labyrinth[i][m + 1] = 1;
    }

    for(int i = 1; i <= k; i++)
        labyrinth[1][ins[i]] = i + 1;

    stack<place> path;
    for(int i = 1; i <= k; i++)
    {
//        /////////////////////////////////
//        cout << "i = " << i << endl;
//        ////////////////////////////////
        while(!path.empty())
        {
            path.pop();
        }
        path.push(make_pair(1, ins[i]));
        int x = path.top().first;
        int y = path.top().second;
        do {
//            /////////////////////////////////////
//            cout << x << " " << y << endl;
//            ////////////////////////////////////
            if(x < n - 1)
            {
                // право-верх
                if ((labyrinth[x - 1][y - 1] == 0/* || labyrinth[x - 1][y - 1] == i + 1*/) &&
                         !isDeadendFromLeftDown(x - 1, y - 1, labyrinth, i) &&
                         !isDeadend(make_pair(x - 1, y - 1)))
                {
                    if(labyrinth[x - 1][y - 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                // право
                else if(labyrinth[x][y - 1] == 0 &&
                   !isDeadendFromLeft(x, y - 1, labyrinth, i) &&
                   !isDeadend(make_pair(x, y - 1)))
                {
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // право-низ
                else if(labyrinth[x + 1][y - 1] == 0 &&
                        !isDeadendFromLeftUp(x + 1, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y - 1)))
                {
                    x++;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // низ
                else if(labyrinth[x + 1][y] == 0 &&
                        !isDeadendFromUp(x + 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y)))
                {
                    x++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-низ
                else if(labyrinth[x + 1][y + 1] == 0 &&
                        !isDeadendFromRightUp(x + 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y + 1)))
                {
                    x++;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево
                else if((labyrinth[x][y + 1] == 0/* || labyrinth[x][y + 1] == i + 1*/) &&
                        !isDeadendFromRight(x, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y + 1))) {
                    if(labyrinth[x][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-верх
                else if((labyrinth[x - 1][y + 1] == 0/* || labyrinth[x - 1][y + 1] == i + 1*/) &&
                        !isDeadendFromRightDown(x - 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y + 1)))
                {
                    if(labyrinth[x - 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // верх
                else if((labyrinth[x - 1][y] == 0/* || labyrinth[x - 1][y] == i + 1*/) &&
                        !isDeadendFromDown(x - 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y)))
                {
                    if(labyrinth[x - 1][y] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                no_exit(path, labyrinth);
                pathsCount--;
                break;
            }
            else if(x == n - 1)
            {
                // право-верх
                if ((labyrinth[x - 1][y - 1] == 0 || labyrinth[x - 1][y - 1] == i + 1) &&
                         !isDeadendFromLeftDown(x - 1, y - 1, labyrinth, i) &&
                         !isDeadend(make_pair(x - 1, y - 1)))
                {
                    if(labyrinth[x - 1][y - 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // право
                else if(labyrinth[x][y - 1] == 0 &&
                        !isDeadendFromLeft(x, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y - 1)))
                {
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                // право-низ
                else if(labyrinth[x + 1][y - 1] != 1 &&
                        !isDeadendFromLeftUp(x + 1, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y - 1)))
                {
                    x++;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // низ
                else if(labyrinth[x + 1][y] != 1 &&
                        !isDeadendFromUp(x + 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y)))
                {
                    x++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-низ
                else if(labyrinth[x + 1][y + 1] != 1 &&
                        !isDeadendFromRightUp(x + 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y + 1)))
                {
                    if(labyrinth[x + 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x++;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево
                else if((labyrinth[x][y + 1] == 0 || labyrinth[x][y + 1] == i + 1) &&
                        !isDeadendFromRight(x, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y + 1))) {
                    if(labyrinth[x][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-верх
                else if((labyrinth[x - 1][y + 1] == 0 || labyrinth[x - 1][y + 1] == i + 1) &&
                        !isDeadendFromRightDown(x - 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y + 1)))
                {
                    if(labyrinth[x - 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // верх
                else if((labyrinth[x - 1][y] == 0 || labyrinth[x - 1][y] == i + 1) &&
                        !isDeadendFromDown(x  - 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y)))
                {
                    if(labyrinth[x - 1][y] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }


                // право-верх
                if ((labyrinth[x - 1][y - 1] == i + 1/* || labyrinth[x - 1][y - 1] == i + 1*/) &&
                    !isDeadendFromLeftDown(x - 1, y - 1, labyrinth, i) &&
                    !isDeadend(make_pair(x - 1, y - 1)))
                {
                    if(labyrinth[x - 1][y - 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // право
                else if(labyrinth[x][y - 1] == i+1 &&
                        !isDeadendFromLeft(x, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y - 1)))
                {
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // право-низ
                else if(labyrinth[x + 1][y - 1] == i + 1 &&
                        !isDeadendFromLeftUp(x + 1, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y - 1)))
                {
                    x++;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // низ
                else if(labyrinth[x + 1][y] == i+ 1 &&
                        !isDeadendFromUp(x + 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y)))
                {
                    x++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-низ
                else if(labyrinth[x + 1][y + 1] == i + 1 &&
                        !isDeadendFromRightUp(x + 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x + 1, y + 1)))
                {
                    x++;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево
                else if((labyrinth[x][y + 1] == i + 1/* || labyrinth[x][y + 1] == i + 1*/) &&
                        !isDeadendFromRight(x, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y + 1))) {
                    if(labyrinth[x][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-верх
                else if((labyrinth[x - 1][y + 1] == i + 1/* || labyrinth[x - 1][y + 1] == i + 1*/) &&
                        !isDeadendFromRightDown(x - 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y + 1)))
                {
                    if(labyrinth[x - 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // верх
                else if((labyrinth[x - 1][y] == i + 1/* || labyrinth[x - 1][y] == i + 1*/) &&
                        !isDeadendFromDown(x - 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y)))
                {
                    if(labyrinth[x - 1][y] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }

                no_exit(path, labyrinth);
                pathsCount--;
                break;
            }
            else if(x == n)
            {
                // право-верх
                if ((labyrinth[x - 1][y - 1] == 0/* || labyrinth[x - 1][y - 1] == i + 1*/) &&
                         !isDeadendFromLeftDown(x - 1, y - 1, labyrinth, i) &&
                         !isDeadend(make_pair(x - 1, y - 1)))
                {
                    if(labyrinth[x - 1][y - 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                // право
                else if((labyrinth[x][y - 1] == 0) &&
                   !isDeadendFromLeft(x, y - 1, labyrinth, i) &&
                   !isDeadend(make_pair(x, y - 1)))
                {
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево
                else if((y < m && labyrinth[x][y + 1] != 1) &&
                        !isDeadendFromRight(x, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y + 1)))
                {
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-верх
                else if(y < m && ((labyrinth[x - 1][y + 1] == 0 || labyrinth[x - 1][y + 1] == i + 1)) &&
                        !isDeadendFromRightDown(x - 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y + 1)))
                {
                    if(labyrinth[x - 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // верх
                else if((labyrinth[x - 1][y] == 0 || labyrinth[x - 1][y] == i + 1) &&
                        !isDeadendFromDown(x - 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y)))
                {
                    if(labyrinth[x - 1][y] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }



                // право-верх
                if ((labyrinth[x - 1][y - 1] == i + 1/* || labyrinth[x - 1][y - 1] == i + 1*/) &&
                    !isDeadendFromLeftDown(x - 1, y - 1, labyrinth, i) &&
                    !isDeadend(make_pair(x - 1, y - 1)))
                {
                    if(labyrinth[x - 1][y - 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // право
                else if((labyrinth[x][y - 1] == 0) &&
                        !isDeadendFromLeft(x, y - 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y - 1)))
                {
                    y--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево
                else if((labyrinth[x][y + 1] != 1) &&
                        !isDeadendFromRight(x, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x, y + 1)))
                {
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // лево-верх
                else if(labyrinth[x - 1][y + 1] == i + 1)) &&
                        !isDeadendFromRightDown(x - 1, y + 1, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y + 1)))
                {
                    if(labyrinth[x - 1][y + 1] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    y++;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }
                    // верх
                else if((labyrinth[x - 1][y] == i + 1) &&
                        !isDeadendFromDown(x - 1, y, labyrinth, i) &&
                        !isDeadend(make_pair(x - 1, y)))
                {
                    if(labyrinth[x - 1][y] == i + 1)
                    {
                        deadends.push_back(make_pair(x, y));
                        labyrinth[x][y] = 0;
                    }
                    x--;
                    path.push(make_pair(x, y));
                    labyrinth[x][y] = i + 1;
                    continue;
                }


                no_exit(path, labyrinth);
                pathsCount--;
                break;
            }
        } while(!isOut(make_pair(x, y)));
    }

    cout << pathsCount << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << labyrinth[i][j];
            if(j != m)
                cout << " ";
        }
        if(i != n)
            cout << endl;
    }

    return 0;
}