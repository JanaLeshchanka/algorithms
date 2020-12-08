#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
//#include <chrono>

using namespace std;

//std::chrono::time_point<std::chrono::system_clock> start, endWork, hkStart, hkEnd;

queue<int> q;
//bool* used;
//int* mt;
int n;
int* pairU;
int* pairV;
int* dist;

//const double eps = 0.0000000000001;

struct postcard {
    double width;
    double length;
};

struct envelope {
    double width;
    double length;
};

bool dfs(int u, vector<vector<int>> list)
{
    int NIL = n;
    int infty = n + 2;
    if(u != NIL)
    {
        for(int v = 0; v < list[u].size(); v++)
        {
            if(dist[pairV[v]] == dist[u] + 1)
            {
                if(dfs(pairV[v], list))
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = infty;
        return false;
    }
    return true;
}

bool bfs(vector<vector<int>> list)
{
    int NIL = n;
    int infty = n + 2;
    for(int u = 0; u < n; u++)
    {
        if(pairU[u] == NIL)
        {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = infty;
        }
        dist[NIL] = infty;
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(dist[u] < dist[NIL])
        {
            for(int v = 0; v < list[u].size(); v++)
            {
                if(dist[pairV[v]] == infty)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }
    return dist[n] != infty;
}

int HopcroftKarp(vector<vector<int>> list)
{
    int NIL = n;
    int infty = n + 2;
    for(int u = 0; u < n; u++)
    {
        pairU[u] = NIL;
    }
    for(int v = 0; v < n; v++)
    {
        pairV[v] = NIL;
    }
    int m = 0;
    while(bfs(list))
    {
        for(int u = 0; u < n; u++)
        {
            if(pairU[u] == NIL)
            {
                if(dfs(u, list))
                {
                    m++;
                }
            }
        }
    }
    return m;
}

//bool kuhn(int v, vector<vector<int>> list)
//{
//    if(used[v] == 1)
//        return false;
//    used[v] = 1;
//    for(int i = 0; i < list.at(v).size(); i++)
//    {
//        int to = list.at(v).at(i);
//        if((mt[to] == -1) || kuhn(mt[to], list))
//        {
//            mt[to] = v;
//            return true;
//        }
//    }
//    return false;
//}

bool fitsWithAngle(double x, double y, double X, double Y)
{
    if(x < y)
    {
        double temp = x;
        x = y;
        y = temp;
    }
    if(X < Y)
    {
        double temp = X;
        X = Y;
        Y = temp;
    }
    if(x * x + y * y > X * X + Y * Y)
        return false;
    if(X * X >= x * x + y * y)
        return Y > x;
    return(X * Y > 2 * x * y) &&
          ((x * x + y * y - Y * Y) * (x * x + y * y - X * X) <= X * X * Y * Y - 4 * X * Y * x * y + 4 * x * x * y * y) && (X * Y - x * y >= 0);
}

bool isFits(postcard c, envelope e)
{
    return ((c.width <= e.width && c.length <= e.length)
            || (c.length <= e.width && c.width <= e.length)
            || fitsWithAngle(c.length, c.width, e.length, e.width));
}

int main() {
//    start = std::chrono::system_clock::now();
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int rib_counter = 0;
    cin >> n;
    pairU = new int[n + 1];
    for(int i = 0; i <= n; i++)
        pairU[i] = 0;
    pairV = new int[n + 1];
    for(int i = 0; i <= n; i++)
        pairV[i] = 0;
    dist = new int[n + 1];
    for(int i = 0; i <= n; i++)
        dist[i] = 0;
    vector<int> arr;
    vector<vector<int>> list(n, arr);
//    used = new bool[n];
//    for(int i = 0; i < n; i++)
//        used[i] = false;
//    mt = new int[n];
//    for(int i = 0; i < n; i++)
//        mt[i] = -1;
    postcard* cards = new postcard[n];
    for(int i = 0; i < n; i++)
    {
        cin >> cards[i].length >> cards[i].width;
    }
    envelope* envs = new envelope[n];
    for(int i = 0; i < n; i++)
    {
        cin >> envs[i].length >> envs[i].width;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(isFits(cards[i], envs[j]))
            {
                list.at(i).push_back(j);
            }
    }

//    hkStart = std::chrono::system_clock::now();
//    for(int i = 0; i < n; i++)
//    {
////        cout << "i = " << i << endl;
//        for(int j = 0; j < n; j++)
//            used[j] = 0;
//        kuhn(i, list);
////        cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << endl;
//    }
//    for(int i = 0; i < n; i++)
//    {
//        if(mt[i] != -1)
//            rib_counter++;
//    }
//    hkEnd = std::chrono::system_clock::now();

//    hkStart = std::chrono::system_clock::now();
    rib_counter = HopcroftKarp(list);
//    hkEnd = std::chrono::system_clock::now();


//    for(int i = 0; i < n; i++)
//    {
////        cout << "i = " << i << endl;
//        for(int j = 0; j < n; j++)
//            used[j] = 0;
//        kuhn(i, list);
////        cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << endl;
//    }
//    for(int i = 0; i < n; i++)
//    {
//        if(mt[i] != -1)
//            rib_counter++;
//    }
    if(rib_counter == n)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO" << endl << rib_counter;
//    endWork = std::chrono::system_clock::now();
//    cout << endl << "algorithm time " << std::chrono::duration_cast<std::chrono::milliseconds>(hkEnd - hkStart).count();
//    cout << endl << "total time " << std::chrono::duration_cast<std::chrono::milliseconds>(endWork - start).count() << endl;
    return 0;
}